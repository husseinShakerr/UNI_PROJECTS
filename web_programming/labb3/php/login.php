<?php
include 'functions.php';

if (isset($_GET['action']) && $_GET['action'] === 'logout') {
    logOut();
}
//Boolean variabel som är true vid rätt inloggning.
$loginResult = checkLogin();

if ($loginResult === true) {
    header("Location: del2.php");
    exit;
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Laboration 3 - Logga in</title>
    <link rel="stylesheet" href="../css/body.css">
    <link rel="stylesheet" href="../css/meny.css">
    <link rel="stylesheet" href="../css/login.css">
</head>
<body>
    <nav id="mainMenu">
        <ul>
            <li><a href="del2.php">Del 2</a></li>
            <li><a href="del3.php">Del 3</a></li>
            <?php if (!empty($_SESSION['loggedIn'])): ?>
                <li id="loginBtn"><a href="login.php?action=logout">Logga ut</a></li>
            <?php else: ?>
                <li id="loginBtn"><a href="login.php">Logga in</a></li>
            <?php endif; ?>
        </ul>
    </nav>

    <div id="logInBox" class="container">
        <h2 id="logInHeader">Logga in</h2>

        <?php
        // Visa felmeddelande vid felaktig inloggning
        if ($loginResult === false) {
            echo "<p style='color:red; text-align:center;'>Fel användarnamn eller lösenord, försök igen.</p>";
        }
        ?>

        <?php if (empty($_SESSION['loggedIn'])): ?>
        <form method="post" action="login.php">
            <label for="uname"><b>Användarnamn</b></label>
            <input type="text" placeholder="Ange användarnamn" name="uname" required>

            <label for="psw"><b>Lösenord</b></label>
            <input type="password" placeholder="Ange lösenord" name="psw" required>

            <button id="logInBtn" type="submit" name="loginBtn">Logga in</button>
        </form>
        <?php else: ?>
            <p style="text-align:center;">Du är redan inloggad som <b><?php echo $_SESSION['user']; ?></b></p>
        <?php endif; ?>
    </div>
</body>
</html>
