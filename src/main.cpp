#include <swiftly/swiftly.h>
#include <swiftly/gameevents.h>
#include <swiftly/server.h>
#include <swiftly/commands.h>

Server *server = nullptr;
PlayerManager *g_playerManager = nullptr;
Commands *commands = nullptr;

void OnProgramLoad(const char *pluginName, const char *mainFilePath)
{
    Swiftly_Setup(pluginName, mainFilePath);

    server = new Server();
    g_playerManager = new PlayerManager();
    commands = new Commands(pluginName);
}

void Command_Resetscore(int playerID, const char **args, uint32_t argsCount, bool silent)
{
    if (playerID == -1)
        return;

    Player *player = g_playerManager->GetPlayer(playerID);
    if (player == nullptr)
        return;

    if (player->stats->Get(KILLS) == 0 && player->stats->Get(DEATHS) == 0 && player->stats->Get(ASSISTS) == 0 && player->stats->Get(DAMAGE) == 0)
        return player->SendMsg(HUD_PRINTTALK, FetchTranslation("resetscore.already_resetted.message"));

    player->stats->Set(KILLS, 0);
    player->stats->Set(DEATHS, 0);
    player->stats->Set(ASSISTS, 0);
    player->stats->Set(DAMAGE, 0);
    player->SendMsg(HUD_PRINTTALK, FetchTranslation("resetscore.resetscore.message"));
}

void OnPluginStart()
{
    commands->Register("resetscore", reinterpret_cast<void *>(&Command_Resetscore));
    commands->Register("rs", reinterpret_cast<void *>(&Command_Resetscore));
}

void OnPluginStop()
{
}

const char *GetPluginAuthor()
{
    return "Swiftly Solution";
}

const char *GetPluginVersion()
{
    return "1.0.0";
}

const char *GetPluginName()
{
    return "Swiftly Resetscore";
}

const char *GetPluginWebsite()
{
    return "https://github.com/swiftly-solution/swiftly_resetscore";
}
