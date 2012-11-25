<?php

/**
 * @file
 * Provide helper function for commerce_qiwi payment module
 */

/**
 * Creates an qiwi payment transaction for the specified charge amount.
 *
 * @param $payment_method
 *   The payment method instance object used to charge this payment.
 * @param $order
 *   The order object the payment applies to.
 * @param $charge
 *   An array indicating the amount and currency code to charge.
 * @param $name
 *   The name entered on the submission form.
 */
function commerce_qiwi_transaction($order_id, $status) {
  if ($order = commerce_order_load($order_id)) {
    $wrapper = entity_metadata_wrapper('commerce_order', $order);

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'commerce_payment_transaction')
      ->propertyCondition('order_id', $order->order_id);
    $result = $query->execute();

    if (isset($result['commerce_payment_transaction'])) {
      $transaction_id = array_keys($result['commerce_payment_transaction']);
      $transaction = commerce_payment_transaction_load($transaction_id[0]);
    }
    else {
      $payment_method = commerce_payment_method_instance_load($order->data['payment_method']);

      $transaction = commerce_payment_transaction_new('commerce_qiwi', $order->order_id);
      $transaction->instance_id = $payment_method['instance_id'];

      $currency_code = $wrapper->commerce_order_total->currency_code->value();
      $amount = $wrapper->commerce_order_total->amount->value();

      $transaction->amount = $order->commerce_order_total[LANGUAGE_NONE][0]['amount'];
      $transaction->currency_code = $order->commerce_order_total[LANGUAGE_NONE][0]['currency_code'];
    }

    $transaction->status = $status;
    $transaction->message = '';
    $transaction->message_variables = array();

    commerce_payment_transaction_save($transaction);
  }
}

/**
 * Helper to returs statuses.
 */
function commerce_qiwi_statuses() {
  $options = array();
  $statuses = commerce_payment_transaction_statuses();
  if (!empty($statuses)) {
    foreach ($statuses as $status) {
      $options[$status['status']] = $status['title'];
    }
  }
  return $options;
}

/**
 * Return setting from variable.
 * @return setting value.
 */
function commerce_qiwi_get_settings($settings) {
  $output = '';
  $vars = variable_get('commerce_qiwi_settings', '');
  if (!empty($vars)) {
    foreach ($vars as $key => $var) {
      if ($key == $settings) {
        $output = $vars[$key]['#default_value'];
        break;
      }
    }
  }
  return $output;
}

/**
 * Commerce get order amount
 */
function commerce_qiwi_get_order_amount($order_in) {
  $order = commerce_order_load($order_in);
  $wrapper = entity_metadata_wrapper('commerce_order', $order);

  $currency_code = $wrapper->commerce_order_total->currency_code->value();
  $amount = $wrapper->commerce_order_total->amount->value();

  return commerce_currency_amount_to_decimal($amount, $currency_code);
}

/**
 * Commerce get order amount
 */
function commerce_qiwi_get_order_currency($order_in) {
  $order = commerce_order_load($order_in);
  $wrapper = entity_metadata_wrapper('commerce_order', $order);

  return $wrapper->commerce_order_total->currency_code->value();
}