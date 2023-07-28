const char HTTP_SCRIPT_CHART_PUMP_TEST[] PROGMEM = 
  "var %s;"
  "function %s(ls,ds){"
    "const c=%s;"
    "c.data.labels=ls;"
    "c.data.dataset.push(ds);"
    "c.update();"
  "}"
  "function %s(){"
    "const c=%s;"
    "c.data.datasets.pop();"
    "c.update();"
  "}"
  "function %s(l,d){"
    "const c=%s;"
    "if(c.data.labels.length>mdp)%s();"
    "c.data.labels.push(l);"
    "for(let i=0;i<c.data.datasets.length;++i)c.data.datasets[i].data.push(d);"
    "c.update();"
  "}"
  "function %s(){"
    "const c=%s;"
    "c.data.labels.splice(-1, 1);"
    "c.data.datasets.forEach(dataset=>{dataset.data.pop();});"
    "c.update();"
  "}"
  "function %s(){"
    "const cn='%s';"
    "const cc='%s';"
    "const u='%s';"
    "const cu=(u==' ')?'':`(${u})`;"
    "%s=new Chart(eb('%s'),{"
      "type:'line',"
      "data:{"
        "datasets:[{"
          "axis:'y',"
          "borderColor: cc,"
          "backgroundColor: cc,"
          "label: `${cn} ${cu}`"
        "}]"
      "},"
      "options:{"
        "reponsive:true,"
        "plugins:{"
          "title:{"
            "display:true,"
            "text: `${cn} Line Chart`"
          "},"
          "decimation:{"
            "enabled:true,"
            "algorithm:'lttb',"
            "samples:mdp"
          "}"
        "},"
        "scales:{"
          "x:{"
            "display:true,"
            "type:'logarithmic',"
            "title:{"
              "display:true,"
              "text:'Time in Seconds'"
            "}"
          "},"
          "y:{"
            "display:true,"
            "type:'logarithmic',"
            "title:{"
              "display:true,"
              "text:'Value'"
            "}"
          "}"
        "}"
      "}"
    "});"
  "}"
  "wl(%s);"
;