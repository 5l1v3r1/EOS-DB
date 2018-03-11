#include <eoslib/eos.hpp>
#include <eoslib/db.hpp>
#include <eoslib/string.hpp>

namespace sample_dbc {
	
	//users
	struct value_users_get {
		eosio::string user_email;
        eosio::string user_uid;
		eosio::string phone;
		eosio::string password;
		eosio::string status;
		eosio::string rating;
        account_name  owner;
    };
	
	struct value_getuser_get {
		eosio::string user_email;
		eosio::string result_operation;
        account_name  owner;
    };
	
	struct value_deluser_get {
		eosio::string user_email;
		eosio::string result_operation;
        account_name  owner;
    };
	
	struct PACKED(by_user){
        eosio::string user_email;
		eosio::string user_uid;
		eosio::string phone;
		eosio::string password;
		eosio::string status;
        eosio::string rating;
    };
	
}