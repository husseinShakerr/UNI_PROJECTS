<?php
include_once 'functions.php';
requireLogIn();
?>

<!DOCTYPE html>
<html>
<head>
    <title>Laboration 3 - Del 3</title>
    <link rel="stylesheet" href="../css/body.css">
    <link rel="stylesheet" href="../css/del3.css">
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
<h2 id = "title">Del 3</h2>
<div id = "info">
    <p id = "infoParagraph">
        <?php
        visaInfo_del3();
        ?>
        </p>
    </div>

</body>
</html>