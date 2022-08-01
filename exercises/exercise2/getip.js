var getIp = function (){
    var ip = $.ajax({ 
       url: 'https://api.ipify.org?format=json', 
       async: false
    }).responseJSON.ip;
    return ip;
};
 
var ip = getIp();

