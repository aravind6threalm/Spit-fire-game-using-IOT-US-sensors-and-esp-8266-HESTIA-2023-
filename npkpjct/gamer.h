const char webpage[] PROGMEM = R"=====(

<!DOCTYPE html>

<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0"/>
<style>

  canvas { background: #eee; }
table{
    border:2px dashed;
    align-content:center;
    width:400px;
    height:150px;
    top:300px;
}
th{
    border:2px solid;
}
#ph,#dht,#dht_hum{

    color:green;
    font-family:'Franklin Gothic Medium', 'Arial Narrow', Arial, sans-serif;

}
</style>
</head>
<body onload="activ()">
<center><h1>TKMCE NPK SOIL tester S4</h1></center>
<center>   
    
    <script>
        function activ(){
            setInterval("getData()",1000);
            setInterval("getData1()",1000);
            setInterval("getData2()",1000);


        }
        var axi;
        var axi1;
        function getData() {
         
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
       axi = this.responseText;
      
     document.getElementById("ph").innerHTML= axi;
     
    }
  };
  xhttp.open("GET", "adcread", true);
  xhttp.send();
  
}
function getData1() {
         
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
       axi1 = this.responseText;
      
     
     document.getElementById("dht").innerHTML= axi1;
    }
  };
  xhttp.open("GET", "adcread1", true);
  xhttp.send();
  
}
var axi2;

function getData2() {
         
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
       axi2 = this.responseText;
      
     
     document.getElementById("dht_hum").innerHTML= axi2;
    }
  };
  xhttp.open("GET", "adcread2", true);
  xhttp.send();
  
}


    </script>


    
    
    <table >
<tr><th>PH value</th><th>DHT Temperature value</th> <th>DHT Humidity value</th></tr>
<tr><th id="ph">ph</th><th id ="dht">dht</th></th><th id ="dht_hum">dht</th></tr>

</table></center>

<span style="position:absolute;color:green;font-size: larger;top:500px;">state: active</span>

</div>
</body>
</html>

)=====";