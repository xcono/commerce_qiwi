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

������ ������������� ����������� ����������� Qiwi-�������� � �������� ������ ������ ������ �� ����� �����. �� ������ ������ ������ ������������ ��� ������ ������, ������� ������������� Qiwi, � �.�. ��������� �����, ����������� ������� � ��������� ������.

������ ������� �� ���� �������� �� ������������ Qiwi. �������� �� ������������� SOAP, ��� ������ ������ �� ��������� ��� ����������, ���� ����������� ��. ����� ������ ������������ ������� ����������, ������� ���������� ������ ����� ��������� Qiwi.

���������
- ���������� � �������� ������
- ��������� � ��������� �������� ������ /admin/commerce/config/payment-methods
- �������������� ������ ������ Qiwi Wallet
- �������� ������� � ������ "��������" (Actions)
- ������� ����� � ������ � �������� Qiwi
- ������� ����� ��� HTTP-��������: http://w.qiwi.ru/setInetBill_utf.do
- ��������� �����
