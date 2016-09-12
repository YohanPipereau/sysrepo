/**
 * @file set_item_example.cpp
 * @author Mislav Novakovic <mislav.novakovic@sartura.hr>
 * @brief Example usage of set_item_example function.
 *
 * @copyright
 * Copyright 2016 Deutsche Telekom AG.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>

#include "Session.h"

using namespace std;

int
main(int argc, char **argv)
{
    try {
        Logs log;
        log.set_stderr(SR_LL_DBG);

	shared_ptr<Connection> conn(new Connection("app3"));

        shared_ptr<Session> sess(new Session(conn));

        /* create new interface named 'gigaeth0' of type 'ethernetCsmacd' */
	const char *xpath = "/ietf-interfaces:interfaces/interface[name='gigaeth0']/type";
	const char *ethernet = "ethernetCsmacd";
        shared_ptr<Val> value(new Val((char *) ethernet, SR_IDENTITYREF_T));
        sess->set_item(xpath, value);

        /* set 'prefix-length' leaf inside of the 'address' list entry with key 'fe80::ab8'
        (list entry will be automatically created if it does not exist) */
        const char *xpath_num = "/ietf-interfaces:interfaces/interface[name='gigaeth0']/ietf-ip:ipv6/address[ip='fe80::ab8']/prefix-length";
        uint8_t num = 64;
        shared_ptr<Val> value_num(new Val(num, SR_UINT8_T));
        sess->set_item(xpath_num, value_num);

	sess->commit();
    } catch( const std::exception& e ) {
        cout << e.what() << endl;
    }


    return 0;
}