(this["webpackJsonpir-hub-web-ui"]=this["webpackJsonpir-hub-web-ui"]||[]).push([[0],[,,,,,,,,function(e,t,a){e.exports=a(16)},,,,,function(e,t,a){},function(e,t,a){},function(e,t,a){},function(e,t,a){"use strict";a.r(t);var n=a(0),l=a.n(n),r=a(2),c=a.n(r),m=(a(13),a(3)),u=a(4),E=a(6),d=a(5),o=a(7),i=(a(14),!0),b=function(e,t){return fetch("/rc5/".concat(function(e,t){var a=3;a|=i<<2,i=!i;for(var n=0;n<5;n++){a|=!!(e&1<<4-n)<<3+n}for(var l=0;l<6;l++){a|=!!(t&1<<5-l)<<8+l}return a}(e,t)))},s=function(e){var t=e.address,a=e.command,n=e.children;return l.a.createElement("button",{onClick:function(){return b(t,a)}},n)},f=function(e){var t=e.code,a=e.children;return l.a.createElement("button",{onClick:function(){return function(e){for(var t="",a=0;a<e.length;a++)t+=e[a],a!==e.length-1&&(t+="/");fetch("/rah2e/".concat(t))}(t)}},a)},y={OFF:[20,99,0,16,16,2,-3]},h=(a(15),function(e){var t=e.address,a=void 0===t?255:t,n=e.byte,r=e.children;return l.a.createElement("button",{onClick:function(){return function(e,t){for(var a=[(65280&e)>>8,255&e,t,~t],n="",l=0;l<a.length;l++)n+=a[l],l!==a.length-1&&(n+="/");fetch("/nec/".concat(n))}(a,n)}},r)}),p=function(){return l.a.createElement("table",{align:"center"},l.a.createElement("tbody",null,l.a.createElement("tr",null,l.a.createElement("td",null,l.a.createElement(h,{byte:64},"Power")),l.a.createElement("td",null,l.a.createElement(h,{byte:18},"Mute"))),l.a.createElement("tr",null,l.a.createElement("td",{colspan:"3"},l.a.createElement("hr",null))),l.a.createElement("tr",null,l.a.createElement("td",null,l.a.createElement(h,{byte:76},"Back")),l.a.createElement("td",null,l.a.createElement(h,{byte:71},"^")),l.a.createElement("td",null,l.a.createElement(h,{byte:86},"Menu"))),l.a.createElement("tr",null,l.a.createElement("td",null,l.a.createElement(h,{byte:72},"<")),l.a.createElement("td",null,l.a.createElement(h,{byte:36},"OK")),l.a.createElement("td",null,l.a.createElement(h,{byte:74},">"))),l.a.createElement("tr",null,l.a.createElement("td",null),l.a.createElement("td",null,l.a.createElement(h,{byte:20},"Down"))),l.a.createElement("tr",null,l.a.createElement("td",{colspan:"3"},l.a.createElement("hr",null))),l.a.createElement("tr",null,l.a.createElement("td",null,l.a.createElement(h,{byte:16},"<<")),l.a.createElement("td",null,l.a.createElement(h,{byte:68},"||>")),l.a.createElement("td",null,l.a.createElement(h,{byte:70},">>"))),l.a.createElement("tr",null,l.a.createElement("td",{colspan:"3"},l.a.createElement("hr",null))),l.a.createElement("tr",null,l.a.createElement("td",null,l.a.createElement(h,{byte:1},"1")),l.a.createElement("td",null,l.a.createElement(h,{byte:2},"2")),l.a.createElement("td",null,l.a.createElement(h,{byte:3},"3"))),l.a.createElement("tr",null,l.a.createElement("td",null,l.a.createElement(h,{byte:4},"4")),l.a.createElement("td",null,l.a.createElement(h,{byte:5},"5")),l.a.createElement("td",null,l.a.createElement(h,{byte:6},"6"))),l.a.createElement("tr",null,l.a.createElement("td",null,l.a.createElement(h,{byte:7},"7")),l.a.createElement("td",null,l.a.createElement(h,{byte:8},"8")),l.a.createElement("td",null,l.a.createElement(h,{byte:9},"9"))),l.a.createElement("tr",null,l.a.createElement("td",null),l.a.createElement("td",null,l.a.createElement(h,{byte:0},"0")),l.a.createElement("td",null))))},v=function(e){function t(){return Object(m.a)(this,t),Object(E.a)(this,Object(d.a)(t).apply(this,arguments))}return Object(o.a)(t,e),Object(u.a)(t,[{key:"render",value:function(){return l.a.createElement("div",{className:"App"},l.a.createElement("div",{className:"button-group"},l.a.createElement("div",{className:"group-header"},"TV"),l.a.createElement(s,{address:1,command:12},"Power"),l.a.createElement(s,{address:1,command:56},"Input"),l.a.createElement(s,{address:1,command:16},"V+"),l.a.createElement(s,{address:1,command:17},"V-")),l.a.createElement("div",{className:"button-group"},l.a.createElement("div",{className:"group-header"},"TV Box"),l.a.createElement(p,null)),l.a.createElement("div",{className:"button-group"},l.a.createElement("div",{className:"group-header"},"A/C"),l.a.createElement(f,{code:y.OFF},"Off")))}}]),t}(l.a.Component);c.a.render(l.a.createElement(v,null),document.getElementById("root"))}],[[8,1,2]]]);
//# sourceMappingURL=main.be75e3b3.chunk.js.map