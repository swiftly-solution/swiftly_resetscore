local resetscorecommand = function(playerid, args, argsCount, silent)
    if playerid == -1 then
        return
    end

    local player = GetPlayer(playerid)
    if player == nil then
        return
    end

    if player:stats():Get(PlayerStat.Kills) == 0 and player:stats():Get(PlayerStat.Deaths) == 0 and player:stats():Get(PlayerStat.Assists) == 0 and player:stats():Get(PlayerStat.Damage) == 0 then
        player:SendMsg(MessageType.Chat, FetchTranslation("resetscore.already_resetted.message"))
        return
    end

    player:stats():Set(PlayerStat.Kills, 0)
    player:stats():Set(PlayerStat.Deaths, 0)
    player:stats():Set(PlayerStat.Assists, 0)
    player:stats():Set(PlayerStat.Damage, 0)
    player:SendMsg(MessageType.Chat, FetchTranslation("resetscore.resetscore.message"))
end

commands:Register("resetscore", resetscorecommand)
commands:Register("rs", resetscorecommand)

events:on("OnPluginStart", function()

end)

function GetPluginAuthor()
    return "moongetsu"
end
function GetPluginVersion()
    return "1.0.0"
end
function GetPluginName()
    return "[Swiftly LUA] ResetScore"
end
function GetPluginWebsite()
    return "https://github.com/moongetsu/swiftly_resetscore"
end