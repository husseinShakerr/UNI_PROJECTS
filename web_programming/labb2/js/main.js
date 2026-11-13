"use strict";

var baseURL = "https://api.sr.se/api/v2/channels/";
var audio = new Audio();

// Wait for DOM to load
document.addEventListener("DOMContentLoaded", function () {
    // Read SR channels and dynamically create list of channels
    let url = baseURL + "?size=100&format=json";
    fetch(url, {method: 'GET'})
        .then(response => response.text())
        .then(data => {
            var jsonData = JSON.parse(data);
            for (var i = 0; i < jsonData.channels.length; i++) {
                document.getElementById("searchProgram").innerHTML += "<option value='" + jsonData.channels[i].id + "'>" + jsonData.channels[i].name + "</option>";
                document.getElementById("mainnavlist").innerHTML += "<li id='" + jsonData.channels[i].id + "'>" + jsonData.channels[i].name + "<img src='" + jsonData.channels[i].image + "'width = 10%>" + "</li>";
            }
        })
        .catch(function(error){
            alert("there was an error" + JSON.stringfy(error));
        });
    // Create eventlistener for click on search program
    document.getElementById('searchbutton').addEventListener("click", function () {
        const channelid = document.getElementById("searchProgram").value;
        if (channelid) {
            let url = baseURL + channelid + "?format=json";
            fetch(url)
                .then(response => response.json())
                .then(data => {
                    document.getElementById("info").innerHTML = `
                    <h1>${data.channel.name}</h1>
                    <img src="${data.channel.image}" width="30%">
                    <p>${data.channel.tagline}</p>
                    <hr>
                `;

                    // Hämta dagens programtablå
                    let today = new Date().toISOString().split("T")[0];
                    console.log(today);
                    let scheduleUrl = `https://api.sr.se/api/v2/scheduledepisodes?channelid=${channelid}&date=${today}&format=json`;

                    fetch(scheduleUrl)
                        .then(response => response.json())
                        .then(scheduleData => {
                            document.getElementById("info").innerHTML += `<h2>Dagens programtablå</h2>`;
                            scheduleData.schedule.forEach(program => {
                                let start = new Date(parseInt(program.starttimeutc.substr(6)));
                                let end = new Date(parseInt(program.endtimeutc.substr(6)));
                                document.getElementById("info").innerHTML += `
                                <div>
                                    <h3>${program.title}</h3>
                                    <p>${program.description}</p>
                                    <small>Starttid: ${start.toLocaleTimeString()}</small>
                                    <hr>
                                    <small>Sluttid: ${end.toLocaleTimeString()}</small>
                                </div>
                                <hr>
                            `;
                            });
                        });
                });
        }
    });


    // Create eventlistener for clicks on dynamically created list of channels in mainnavlist
    document.getElementById('mainnavlist').addEventListener("click", function (e) {
        var channelid = e.target.id;
        var currentTime = new Date().toISOString().split("T")[0];
        console.log(channelid);
        if (channelid) {
            let url = baseURL + channelid + "?format=json";
            fetch(url, {method: 'GET'})
                .then(response => response.json())
                .then(data => {
                    document.getElementById("info").innerHTML = `
                        <h1>${data.channel.name}</h1>
                        <img src = "${data.channel.image}" width = "30%">
                        <p>${data.channel.tagline}</p>
                        <hr>
                        `;
                    if (!audio.paused) {
                        audio.pause();
                        audio.currentTime = 0;
                    }
                    let audioURL = data.channel.liveaudio.url;
                    audio.src = audioURL;
                    audio.play();
                    let playListURL = `https://api.sr.se/api/v2/playlists/rightnow?channelid=${channelid}&format=json`;
                    fetch(playListURL).then(response => response.json()).then(playListData => {
                        const prevHit = playListData.playlist.previoussong;
                        const nextHit = playListData.playlist.song;
                        if (nextHit) {
                            document.getElementById("info").innerHTML += `
                            <p> Nästa låt: ${nextHit.artist}, ${nextHit.title}</p>
                            `;
                        } else {
                            document.getElementById("info").innerHTML += `<p> Nästa låt: "Ingen tillgänglig information</p>`;
                        }
                        if (prevHit) {
                            document.getElementById("info").innerHTML += `
                            <p> Föregående låt: ${prevHit.artist}, ${prevHit.title}</p>
                            `;
                        } else {
                            document.getElementById("info").innerHTML += `<p> Nästa låt: "Ingen tillgänglig information</p>
                            `;
                        }
                    });

                })
                .catch(error => {
                    console.log("Fel vi fetch: ", error);
                });

        }
    });

})// End of DOM content loaded
