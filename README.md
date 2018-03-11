# EOS-DB
Sample usage EOS as DataBase


# DELETE USER

./eosc push message sampleacc deluser '{"user_email":"email@email","result_operation":"","owner":"inita"}' --scope inita --permission inita@active


# ADD USER

./eosc push message sampleacc adduser '{"user_email":"email@email","user_uid":"1000","phone":"phone 1000","password":"password 1000","status":"status user 1000","rating":"good rating 1000","owner":"inita"}' --scope inita --permission inita@active

# GET ALL ROWS

./eosc get table inita sampleacc sampledbusers

# OR

curl http://127.0.0.1:8888/v1/chain/get_table_rows -X POST -d '{"scope":"inita", "code":"sampleacc", "table":"sampledbusers", "json": true, "limit":10}'
