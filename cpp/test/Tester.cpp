#define CATCH_CONFIG_DEFAULT_REPORTER "junit"
#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

#ifdef EMSCRIPTEN
EM_JS(void, mountIDBFS, (), {
    Asyncify.handleSleep(function(wakeUp) {
        FS.mkdir('/data_idbfs');
        FS.mount(IDBFS, {}, '/data_idbfs');
        FS.syncfs(
            true, function(err) {
                wakeUp();
            });
    });
});
#endif

int main(int the_argc, char** the_argv) noexcept
{
    try
    {
#ifdef EMSCRIPTEN
        mountIDBFS();
#endif

        const int result = Catch::Session().run(the_argc, the_argv);

        return result;
    }
    catch (...)
    {
        return -1;
    }
}
