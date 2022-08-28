#include "utils/hook.h"
#include "lib.h"
#include "addrs.h"
#include "utils/patch.h"

#define HOOK_DEF(rettype, name, params)                                                            \
    typedef rettype(*tww_##name##_t) params;                                                        \
    tww_##name##_t name##Trampoline;

HOOK_DEF(void, draw, (void*));
HOOK_DEF(void, cDyl_InitAsync, (void*, void*, void*));
HOOK_DEF(void, fapGm_Execute, (void));

struct {
    uint32_t a[2];
} trampolines[HOOK_AMNT];

namespace Hook {

void drawHook(void* p1) {
    drawTrampoline(p1);
    draw();
}

void initHook(void* p1, void* p2, void* p3) {
    cDyl_InitAsyncTrampoline(p1, p2, p3);
    init();
}

void gameLoopHook(void) {
    game_loop();
    fapGm_ExecuteTrampoline();
}

void applyHooks() {
#define APPLY_HOOK(name, addr, idx, func)                                                          \
    name##Trampoline = hookFunction((tww_##name##_t)addr, trampolines[idx].a, func)
    APPLY_HOOK(draw, tww_draw_console_addr, HK_LIB_DRAW_INDEX, drawHook);
    APPLY_HOOK(cDyl_InitAsync, tww_cDyl_InitAsync_addr, HK_LIB_INIT_INDEX, initHook);
    APPLY_HOOK(fapGm_Execute, tww_fapGm_Execute_addr, HK_LIB_GAME_LOOP_INDEX, gameLoopHook);

#undef APPLY_HOOK
}
}  // namespace Hook