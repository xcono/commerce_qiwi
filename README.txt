This project integrates Qiwi Wallet into the Drupal Commerce payment. It currently supports off-site payment via Qiwi Terminals and on-site Qiwi money and credit card payment via Qiwi Wallet.

About
Module based on Qiwi protocol description. It is not required SOAP on your server.
Commerce QIWI actively uses transactions statuses. It means you can control post-paid transaction via terminals and credit cards.

Installing
- Install and enable module
- Go to /admin/commerce/config/payment-methods
- Edit Qiwi Wallet payment method
- Edit element under Actions sections
- Enter your Qiwi merchant ID, password
- Enter Qiwi http post uri: http://w.qiwi.ru/setInetBill_utf.do
- Save form

Модуль предоставляет возможность подключения Qiwi-кошелька в качестве метода приема оплаты на вашем сайте. На данный момент модуль поддерживает все методы оплаты, которые предоставляет Qiwi, в т.ч. кредитные карты, электронный кошелек и терминалы оплаты.

Модуль написан на базе примеров из документации Qiwi. Несмотря на использование SOAP, для работы модуля не требуется эта библиотека, либо аналогичные ей. Метод оплаты поддерживает статусы транзакций, включая отложенную оплату через терминалы Qiwi.

Установка
- Установите и включите модуль
- Перейдите в настройки способов оплаты /admin/commerce/config/payment-methods
- Отредактируйте способ оплаты Qiwi Wallet
- Измените элемент в секции "Действия" (Actions)
- Укажите логин и пароль к мерчанту Qiwi
- Укажите адрес для HTTP-запросов: http://w.qiwi.ru/setInetBill_utf.do
- Сохраните форму