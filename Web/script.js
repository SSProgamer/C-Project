function spoil() {
        var element = document.getElementById("spoil");
        var btn = document.getElementById("btn");
        if( element.style.display == "none" ) {
            element.style.display = "block";
            btn.value = "ซ่อน code";
        } else {
            element.style.display = "none";
            btn.value = "แสดง code";
        }
    }