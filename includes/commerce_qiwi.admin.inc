<?php
/**
 * @file
 * Provide admin form for commerce_qiwi payment module
 */

/**
 * Payment method callback: settings form.
 */
function commerce_qiwi_settings_form($settings = NULL) {
  $form = array();

  $settings = (array) $settings + array(
    'merchant_id' => '',
    'password' => '',
    'url' => '',
    'status' => array('pending'),
    'success_message' => '',
    'fail_message' => '',
  );

  $form['merchant_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Login'),
    '#description' => t('Your Qiwi merchant ID'),
    '#default_value' => $settings['merchant_id'],
  );

  $form['password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#description' => t('Your Qiwi merchant password'),
    '#default_value' => $settings['password'],
  );

  $form['url'] = array(
    '#type' => 'textfield',
    '#title' => t('Qiwi URL'),
    '#description' => t('Qiwi payment gate url. Example, w.qiwi.ru/setInetBill.do'),
    '#default_value' => $settings['url'],
  );


  $form['status'] = array(
    '#type' => 'select',
    '#title' => t('Status'),
    '#description' => t('Choose order status after customer sent the order'),
    '#options' => commerce_qiwi_statuses(),
    '#default_value' => $settings['status'],
  );

  $form['success_message'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
    '#title' => t('Success message'),
    '#description' => t('Enter optional text that will be displayed when payment succesful'),
    '#default_value' => $settings['success_message'],
  );

  $form['fail_message'] = array(
    '#type' => 'textarea',
    '#rows' => 3,
    '#title' => t('Fail message'),
    '#description' => t('Enter optional text that will be displayed when payment fail'),
    '#default_value' => $settings['fail_message'],
  );

  $form['#submit'][] = variable_set('commerce_qiwi_settings', $form);

  return $form;
}