const char HTTP_HEADER2[] PROGMEM =   
	"<script>"
    "var x=null,lt,to,tp,pc='';"            // x=null allow for abortion

  // Following bytes saving ES6 syntax fails on old browsers like IE 11 - https://kangax.github.io/compat-table/es6/
    "eb=s=>document.getElementById(s);"     // Alias to save code space
    "qs=s=>document.querySelector(s);"      // Alias to save code space
    "sp=i=>eb(i).type=(eb(i).type==='text'?'password':'text');"  // Toggle password visibility
    "wl=f=>window.addEventListener('load',f);"; // Execute multiple window.onload