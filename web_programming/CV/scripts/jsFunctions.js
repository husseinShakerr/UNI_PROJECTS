function toggleNav() {
    const panel = document.getElementById("sidePanel");
    if (panel.style.width === "200px") {
        panel.style.width = "0";
    } else {
        panel.style.width = "200px";
    }
}


document.addEventListener("DOMContentLoaded", ()=>{
    const ex_ed = document.querySelectorAll(".exp_edu_box h3");
    ex_ed.forEach(obj=>{
        obj.addEventListener("click", ()=>{
            const parent = obj.parentElement;
            parent.classList.toggle("active");
        })
    })
});