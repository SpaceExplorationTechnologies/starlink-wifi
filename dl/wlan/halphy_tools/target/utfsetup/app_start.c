#include <osapi.h>

void utfsetup_main(void);

void
app_start(void)
{
    if (!A_INIT()) {
        A_PRINTF("A_INIT() FAILED.\n");
        return;
    }

    {
        A_old_wdt_t old_wdt;

        A_WDT_DISABLE(&old_wdt);
    }

    utfsetup_main();
}

