--- a/extensions/LUA/lua/ltablib.c
+++ b/extensions/LUA/lua/ltablib.c
@@ -10,11 +10,11 @@
 #define ltablib_c
 #define LUA_LIB
 
-#include "lua.h"
-
 #include "lauxlib.h"
 #include "lualib.h"
 
+#include "lua.h"
+
 
 #define aux_getn(L,n)	(luaL_checktype(L, n, LUA_TTABLE), luaL_getn(L, n))
 
