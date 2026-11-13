<?php
include_once 'functions.php';
requireLogIn();
?>

<!DOCTYPE html>
<html>
<head>
    <title>Laboration 3</title>
    <link rel="stylesheet" href="../css/body.css">
    <link rel="stylesheet" href="../css/del2.css">
    <link rel="stylesheet" href="../css/meny.css">
</head>
<body>
    <nav id = "mainMenu">
            <ul>
                <li><a href="del2.php">Del 2</a></li>
                <li><a href="del3.php">Del 3</a></li>
                <li id = "loginBtn"><a href="login.php">Logga in</a></li>
            </ul>
            </nav>
<h2 id = "title">Del 2</h2>
<div id = "del2_questions">
    <p id = "questions"> 1. Har du tidigare erfarenhet av utveckling med PHP?<br>
    2. Hur har du valt att struktrera upp dina filer och kataloger?<br>
    3. Har du följt guiden, eller skapat på egen hand?<br>
    4. Vilken utvecklingsmiljö har du använt för uppgiften?<br>
    5. Har något varit svårt med denna uppgift?</P>
</div>
<div id = "svar">
    <p id = "mina_svar">
        Nej jag har ingen erfarenhet av PHP. <br>
        Jag har valt att struktrera min filstruktur på egen hand. Jag följde inte guiden. <br>
        Jag har använt VirtualHost så jag kan komma åt mina sidor smidigt. Hjälpsamt för nästkommande uppgifter/labbar.
        Jag använder phpStorm samt webStorm från jetBrains som utvecklingsmiljö, jetBrains har phpStrom specifikt IDE för php programmering,
        men webStorm funkar lika bra känner jag hittills.
        Hittills har inget varit svårt med denna uppgift, men mycket information att ta in på en gång.
        </p>
</div>
</body>
</html>
