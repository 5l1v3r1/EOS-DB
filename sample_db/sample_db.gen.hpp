#pragma once
#include <eoslib/types.hpp>
#include <eoslib/message.hpp>
#include <eoslib/datastream.hpp>
#include <eoslib/raw_fwd.hpp>

namespace eosio { namespace raw {
	
//SAVE USER DATA
template<typename Stream> inline void pack( Stream& s, const sample_dbc::value_users_get& value ) {
		raw::pack(s, value.user_email);
		raw::pack(s, value.user_uid);
		raw::pack(s, value.phone);
		raw::pack(s, value.password);
		raw::pack(s, value.status);
		raw::pack(s, value.rating);
		raw::pack(s, value.owner);
    }
    template<typename Stream> inline void unpack( Stream& s, sample_dbc::value_users_get& value ) {
		raw::unpack(s, value.user_email);
		raw::unpack(s, value.user_uid);
		raw::unpack(s, value.phone);
		raw::unpack(s, value.password);
		raw::unpack(s, value.status);
		raw::unpack(s, value.rating);
		raw::unpack(s, value.owner);
    }
	
//GET USER DATA
    template<typename Stream> inline void pack( Stream& s, const sample_dbc::value_getuser_get& value ) {
	raw::pack(s, value.user_email);
	raw::pack(s, value.owner);
    }
    template<typename Stream> inline void unpack( Stream& s, sample_dbc::value_getuser_get& value ) {
      raw::unpack(s, value.user_email);
      raw::unpack(s, value.owner);
    }
	
	//DELETE USER
		//OUTPUT PARAMS
	template<typename Stream> inline void pack( Stream& s, const sample_dbc::value_deluser_get& value ) {
      raw::pack(s, value.user_email);
	  raw::pack(s, value.result_operation);
	  raw::pack(s, value.owner);
    }
		//INPUT PARAMS
	template<typename Stream> inline void unpack( Stream& s, sample_dbc::value_deluser_get& value ) {
      raw::unpack(s, value.user_email);
	  raw::unpack(s, value.result_operation);
      raw::unpack(s, value.owner);
    }
} }

#include <eoslib/raw.hpp>
namespace eosio {
    void print_ident(int n){while(n-->0){print("  ");}};
    template<typename Type>
    Type current_message_ex() {
      uint32_t size = message_size();
      char* data = (char *)eosio::malloc(size);
      assert(data && read_message(data, size) == size, "error reading message");
      Type value;
      eosio::raw::unpack(data, size, value);
      eosio::free(data);
      return value;
    }

	//ADD NEW USER
		//RETURN DATA
    template<>
    sample_dbc::value_users_get current_message<sample_dbc::value_users_get>() {
      return current_message_ex<sample_dbc::value_users_get>();
    } 
	
	//GET USER INFO
		//RETURN DATA
    template<>
    sample_dbc::value_getuser_get current_message<sample_dbc::value_getuser_get>() {
      return current_message_ex<sample_dbc::value_getuser_get>();
    }
	
	//DELETE USER
		//RETURN DATA
    template<>
    sample_dbc::value_deluser_get current_message<sample_dbc::value_deluser_get>() {
      return current_message_ex<sample_dbc::value_deluser_get>();
    }
	
}
