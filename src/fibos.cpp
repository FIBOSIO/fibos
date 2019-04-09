/*
 * fibos.cpp
 *
 *  Created on: Jun 1, 2018
 *      Author: lion
 */

#include "fibjs.h"
#include "object.h"

#include <appbase/application.hpp>

#include <eosio/chain_plugin/chain_plugin.hpp>
#include <eosio/http_plugin/http_plugin.hpp>
#include <eosio/history_plugin.hpp>
#include <eosio/net_plugin/net_plugin.hpp>
#include <eosio/producer_plugin/producer_plugin.hpp>
#include <eosio/utilities/common.hpp>

#include <fc/log/logger_config.hpp>
#include <fc/log/appender.hpp>
#include <fc/exception/exception.hpp>

#include <boost/dll/runtime_symbol_info.hpp>
#include <boost/exception/diagnostic_information.hpp>

using namespace appbase;
using namespace eosio;

namespace fc {
std::unordered_map<std::string, appender::ptr>& get_appender_map();
}

namespace fibjs {
void importModule()
{
    IMPORT_MODULE(assert);
    IMPORT_MODULE(base32);
    IMPORT_MODULE(base64);
    IMPORT_MODULE(base64vlq);
    IMPORT_MODULE(bson);
    IMPORT_MODULE(buffer);
    IMPORT_MODULE(coroutine);
    IMPORT_MODULE(crypto);
    IMPORT_MODULE(db);
    IMPORT_MODULE(dgram);
    IMPORT_MODULE(dns);
    IMPORT_MODULE(encoding);
    IMPORT_MODULE(events);
    IMPORT_MODULE(fs);
    IMPORT_MODULE(gd);
    IMPORT_MODULE(hash);
    IMPORT_MODULE(hex);
    IMPORT_MODULE(http);
    IMPORT_MODULE(iconv);
    IMPORT_MODULE(io);
    IMPORT_MODULE(json);
    IMPORT_MODULE(mq);
    IMPORT_MODULE(net);
    IMPORT_MODULE(os);
    IMPORT_MODULE(path);
    IMPORT_MODULE(process);
    IMPORT_MODULE(profiler);
    IMPORT_MODULE(punycode);
    IMPORT_MODULE(querystring);
    IMPORT_MODULE(ssl);
    IMPORT_MODULE(string_decoder);
    IMPORT_MODULE(test);
    IMPORT_MODULE(timers);
    IMPORT_MODULE(tty);
    IMPORT_MODULE(url);
    IMPORT_MODULE(util);
    IMPORT_MODULE(uuid);
    IMPORT_MODULE(vm);
    IMPORT_MODULE(ws);
    IMPORT_MODULE(xml);
    IMPORT_MODULE(zip);
    IMPORT_MODULE(zlib);
    IMPORT_MODULE(zmq);
}
}

int32_t main(int32_t argc, char* argv[])
{
    fibjs::importModule();

    fibjs::start(argc, argv, fibjs::main_fiber);
    fibjs::run_gui();

    app().register_plugin<history_plugin>();

    return 0;
}
