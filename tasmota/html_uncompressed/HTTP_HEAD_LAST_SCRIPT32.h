const char HTTP_HEAD_LAST_SCRIPT32[] PROGMEM =
  "function jd(){"                        // Add label name='' based on provided id=''
    "var t=0,i=document.querySelectorAll('input,button,textarea,select');"
    "while(i.length>=t){"
      "if(i[t]){"
        "i[t]['name']=(i[t].hasAttribute('id')&&(!i[t].hasAttribute('name')))?i[t]['id']:i[t]['name'];"
      "}"
      "t++;"
    "}"
  "}"
  "function sf(s){"
    "var t=0,i=document.querySelectorAll('.hf');"
    "while(i.length>=t){"
      "if(i[t]){"
        "i[t].style.display=s?'block':'none';"
      "}"
      "t++;"
    "}"
  "}"
  "wl(jd);"                               // Add name='' to any id='' in input,button,textarea,select
  // experimental
  "function su(t){"
    "eb('f3').style.display='none';"
    "eb('f2').style.display='block';"
    "t.form.submit();"
  "}"
  "function upl(t){"                            // check file's first byte to decide next step
    "var sl=t.form['u2'].files[0].slice(0,1);"  // load only first byte of file
    "var rd=new FileReader();"
    "rd.onload=()=>{"
      "var bb=new Uint8Array(rd.result);"
      "if(bb.length==1&&bb[0]==0xE9){"
        "fct(t);"            // upload via factory
      "}else{"
        "t.form.submit();"  // normal upload
      "};"
    "};"
    "rd.readAsArrayBuffer(sl);"
    "return false;"
  "};"

  "function fct(t){"
    "var x=new XMLHttpRequest();"
    "x.open('GET','/u4?u4=fct&api=',true);"
    "x.onreadystatechange=()=>{"
      "if(x.readyState==4&&x.status==200){"
        "var s=x.responseText;"
        "if(s=='false')setTimeout(()=>{fct(t);},6000);"
        "if(s=='true')su(t);"
      "}else if(x.readyState==4&&x.status==0){"
        "setTimeout(()=>{fct(t);},2000);"             // retry in 2 seconds
      "};"
    "};"
    "x.send();"
  "}"
  "</script>";
