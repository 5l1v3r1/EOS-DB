/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <sample_db.hpp>
#include <sample_db.gen.hpp>
namespace sample_dbc {
    const static uint32_t MAX_STRING_LEN = 1024;
    const static auto CODE_NAME = N(account_name);
	const static auto TABLE_USER = N(sampledbusers);
    

    /*
        char tmp[MAX_STRING_LEN];
        int32_t load_len = load_str(get_param.owner, CODE_NAME, TABLE_NAME,
                                    (char *)get_param.tag.get_data(), get_param.tag.get_size(),
                                    tmp, MAX_STRING_LEN);
		if(load_len != -1){
			eosio::print( "DONT EXIST VALUE" "\n" );
		}
	*/
	//IF SAVE OR UPDATE == 1 success
	//IF FOUND == -1 not found
	//ADD NEW USER
	void apply_add_user(const sample_dbc::value_users_get& get_param)
    {
        eosio::print("sample : ADD USER" "\n" );
        eosio::require_auth(get_param.owner);

		bytes b = eosio::raw::pack(get_param);
		uint32_t err = store_str(get_param.owner, TABLE_USER, (char *)get_param.user_email.get_data(), get_param.user_email.get_size(), (char *)b.data, b.len);
		
		if(err == 1){ eosio::print( "SUCCESS ADDED" "\n" ); }
		else if(err == 0){ eosio::print( "SUCCESS UPDATED" "\n" ); }
    }
	
	//GET USER INFO
	void apply_get_user(const sample_dbc::value_getuser_get& get_param)
    {
        eosio::print("sample : GET USER INFO ["+ get_param.user_email +"] " "\n" );
        eosio::require_auth(get_param.owner);
		
		bytes b = eosio::raw::pack(get_param);
        char tmp[MAX_STRING_LEN];
		int32_t load_len = 0;
        load_len = load_str(get_param.owner, CODE_NAME, TABLE_USER,
                                    (char *)get_param.user_email.get_data(), get_param.user_email.get_size(), tmp, MAX_STRING_LEN);
        if(load_len == -1){
			eosio::print( "USER DONT EXIST" "\n" );
		}else if(load_len != -1){
			eosio::print( "USER EXIST" "\n" );
		}
    }
	
	//DELETE USER
	void apply_del_user(const sample_dbc::value_deluser_get& get_param)
    {
        eosio::print("sample : DELETE USER ["+ get_param.user_email +"] " "\n" );
        eosio::require_auth(get_param.owner);
		
		int32_t load_len = 0;
		load_len = remove_str(get_param.owner, TABLE_USER, (char *)get_param.user_email.get_data(), get_param.user_email.get_size());
		
		if(load_len == 1){
			eosio::print( "USER REMOVED" "\n" );
		}else if(load_len == 0){
			eosio::print( "USER NOT FOUNDED" "\n" );
		}
		//result_operation = ""
    }
}

extern "C" {

    void init()  {
       eosio::print( "Init sample!\n" );
    }

    void apply( uint64_t code, uint64_t action ) {
       eosio::print( "sample READ PARAMS: ", eosio::name(code), "->", eosio::name(action), "\n" );
       if(action == N(adduser))
       {
			sample_dbc::apply_add_user(eosio::current_message<sample_dbc::value_users_get>());
       }
	   else if(action == N(getuser))
       {
			sample_dbc::apply_get_user(eosio::current_message<sample_dbc::value_getuser_get>());
       }
	   else if(action == N(deluser))
       {
			sample_dbc::apply_del_user(eosio::current_message<sample_dbc::value_deluser_get>());
       }
	   else{
			eosio::print( "sample READ PARAMS: UNKNOWN ACTION" "\n" );
	   }
    }

}
