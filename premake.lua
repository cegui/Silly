project.name = "SILLY"
project.bindir = "bin"
project.libdir = "lib"

package = newpackage()
package.name = "SILLY"
package.kind = "dll"
package.language = "c++"

package.files = {
    matchfiles("src/*.cpp"),
    matchfiles("src/loaders/*.cpp"),
    matchfiles("include/*.h"),
    matchfiles("include/*.icpp"),
    matchfiles("include/loaders/*.h"),
    matchfiles("include/loaders/*.icpp"),
}

package.includepaths = {
    "include",
    "include/loaders",
}

-- windows stuff
package.defines = {"WIN32", "_WIN32", "__WIN32__", "SILLY_EXPORTS"}

--
-- Debug
--

    local debug = package.config["Debug"]
    debug.defines = { "DEBUG", "_DEBUG" }
    debug.target = "SILLY_d"
    debug.links = {
    }

--
-- Release
--

    local release = package.config["Release"]
    release.buildflags =
    {
        "no-frame-pointer",
        "no-symbols",
        "optimize-speed"
    }
    release.links = {
    }
