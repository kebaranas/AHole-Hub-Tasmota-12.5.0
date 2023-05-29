const char HTTP_SCRIPT_ROOT[] PROGMEM =
  "var rfsh=1,ft;"
  "function la(p){"
    "a=p||'';"
    "clearTimeout(ft);clearTimeout(lt);"
    "if(x!=null){x.abort();}"             // Abort if no response within 2 seconds (happens on restart 1)
    "x=new XMLHttpRequest();"
    "x.onreadystatechange=()=>{"
      "if(x.readyState==4&&x.status==200){"
        "if(eb('l1')){"
          "eb('l1').innerHTML=\"<table></table>\";"
        "}"
        "if(eb('l2')){"
          "var s=x.responseText.replace(/{t}/g,\"<table style='width:100%%'>\")"
                              ".replace(/{s}/g,\"<tr><th>\")"
                              ".replace(/{m}/g,\"</th><td style='width:20px;white-space:nowrap'>\")"  // I want a right justified column with left justified text
                              ".replace(/{e}/g,\"</td></tr>\");"
          "eb('l2').innerHTML=s;"
        "}"
        "clearTimeout(ft);clearTimeout(lt);"
        "if(rfsh){"
          "lt=setTimeout(la,%d);"               // Settings.web_refresh
        "}"
      "}"
    "};"
    "if(rfsh){"
      "x.open('GET','.?m=1'+a,true);"       // ?m related to Webserver->hasArg("m")
      "x.send();"
      "ft=setTimeout(la,2e4);"              // 20s failure timeout
    "}"
  "}"
  "function seva(par,ivar){"
    "la('&sv='+ivar+'_'+par);"
  "}"
  "function siva(par,ivar){"
    "rfsh=1;"
    "la('&sv='+ivar+'_'+par);"
    "rfsh=0;"
  "}"
  "function sivat(par,ivar){"
    "rfsh=1;"
    "par = par.slice(0, 2) + par.slice(3);"
    "la('&sv='+ivar+'_'+par);"
    "rfsh=0;"
  "}"
  "function pr(f){"
    "if(f){"
      "clearTimeout(lt);clearTimeout(ft);"
      "lt=setTimeout(la,%d);"
      "rfsh=1;"
    "}else{"
      "clearTimeout(lt);clearTimeout(ft);"
      "rfsh=0;"
    "}"
  "}"
  ;
