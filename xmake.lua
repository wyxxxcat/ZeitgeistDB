add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})
set_languages("c++23")
set_project("ZeitgeistDB")
set_version("0.1")
add_includedirs("src/include")

add_requires("linenoise", "simdjson", "rapidjson", "gtest")

target("ZeitgeistDB")
    set_kind("binary")
    add_files("src/**.cpp")
    add_packages("linenoise", "simdjson", "rapidjson", "gtest")

target("tests")
    set_kind("binary")
    add_files("src/**.cpp|main.cpp")

    add_files("tests/**.cpp")

    add_packages("linenoise", "simdjson", "rapidjson", "gtest")

set_default("ZeitgeistDB")