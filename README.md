# EOS-DB
Sample usage EOS as DataBase

# HOW CREATE CONTRACT

curl http://127.0.0.1:8888/v1/wallet/create -X POST -d '"testwallet"'
->returned
PW5KUCUtm9cVBXhGWMQGxvuKNWK7XYy

curl http://127.0.0.1:8888/v1/wallet/unlock -X POST -d '["testwallet","PW5KUCUtm9cVBXhGWMQGxvuKNWK7XYy"]'

./eosc create key

->returned

Private key: 5KQB5gfmiZZfnVZjyLGYfUehT

Public key: EOS6NJfqnQKkw3QkissvUj9fo4

./eosc wallet import -n testwallet 5KQB5gfmiZZfnVZjyLGYfUehT

->returned

imported private key for: EOS6NJfqnQKkw3QkissvUj9fo4

./eosc create key

->returned

Private key: 5KQB5gfmiZZfnVZjyLGYfUe

Public key: EOS6NJfqnQKkw3QkissvUj9f

./eosc wallet import -n testwallet 5KQB5gfmiZZfnVZjyLGYfUe

->returned

imported private key for: EOS6NJfqnQKkw3QkissvUj9f

open config.ini

import faucet-private-key

./eosc wallet import -n testwallet 5KQB5gfmiZZfnVZjynytnt

->returned

imported private key for: EOS6NJfqnQKkw3QkissvUj9f

./eosc create account inita sampleacc EOS6NJfqnQKkw3QkissvUj9fo4 EOS6NJfqnQKkw3QkissvUj9f

create WAST file

cd /root/eos/build/tools

./eoscpp -o /root/eos/contracts/sampleacc/test.wast /root/eos/contracts/test/test.cpp

set contract

cd /root/eos/build/programs/eosc/

./eosc set contract sampleacc /root/eos/contracts/test/test.wast /root/eos/contracts/test/test.abi


# DELETE USER

./eosc push message sampleacc deluser '{"user_email":"email@email","result_operation":"","owner":"inita"}' --scope inita --permission inita@active


# ADD USER

./eosc push message sampleacc adduser '{"user_email":"email@email","user_uid":"1000","phone":"phone 1000","password":"password 1000","status":"status user 1000","rating":"good rating 1000","owner":"inita"}' --scope inita --permission inita@active

# GET ALL ROWS

./eosc get table inita sampleacc sampledbusers

# OR

curl http://127.0.0.1:8888/v1/chain/get_table_rows -X POST -d '{"scope":"inita", "code":"sampleacc", "table":"sampledbusers", "json": true, "limit":10}'
