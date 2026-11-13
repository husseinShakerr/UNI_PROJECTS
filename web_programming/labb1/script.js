$(document).ready(function() {
    $("#submitButton").click(function(event) {
        event.preventDefault();

        const company = $("#company").val();
        const name = $("#name").val();
        const title = $("#title").val();
        const tp = $("#telephone").val();
        const email = $("#email").val();
        if(!email.includes("@")){
            alert("Email-adressen måste innehålla '@'.");
        }
        const bgColor = $("#BGC").val();
        const tColor = $("#textColor").val();
        const font = $("#type").val();


        $("#card").html(`
            <div class="visitCard" style="background-color:${bgColor}; color:${tColor}; font-family:${font};">
                <h3>${company}</h3>
                <p><strong>${name}</strong></p>
                <p>${title}</p>
                <p>${tp}</p>
                <p>${email}</p>
            </div>
        `);

        $("#visitCardForm").hide();
        $("#visitCardPrev").show();
    });

    $("#resetButton").click(function() {
        $("#visitCardForm").reset();
    });

    $("#backButton").click(function() {
        $("#visitCardForm").show();
        $("#visitCardPrev").hide();
    });
});