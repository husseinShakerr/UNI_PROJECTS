<?php
function visaInfo_del3(){
$date = date("Y/M/D");
$dow = date("w");  //Returnerar  0 för söndagar, 1 för måndagar...osv
$ip = $_SERVER['REMOTE_ADDR'];
$fileName = $_SERVER['PHP_SELF'];
$userAgent = $_SERVER['HTTP_USER_AGENT'];
$browser = get_browser();
$browserName_version = $browser->browser. "---".$browser->version;
$os = php_uname();

//Meddelande baserat på vad det är för dag i veckan.
switch($dow){
    case 0:
    $message = "Sista dagen på veckan.";
    break;
    case 1:
    $message = "Nu börjar veckan.";
    break;
    case 2:
    $message = "Tisdag är jobbig dag.";
    break;
    case 3:
    $message = "Lillördag.";
    break;
    case 4:
    $message = "Torsdag är jobbig dag.";
    case 5:
    $message = "Äntligen fredag.";
    case 6:
    $message = "Lördag är den roligaste dagen i veckan.";
}
echo $date." --- ".$message."<br>";
echo "Din IP adress är: ".$ip."<br>";
echo "Sökväg/filnamn: ".$fileName."<br>";
echo "Webbläsare: ".$browserName_version."<br>";
echo "Operativsystem: ". $os."<br>";
}
?>

<?php
session_start();
function checkLogin() {
    $correctUser = "Hussein";
    $correctPass = "12345";
    if (isset($_POST['loginBtn'])) {
        $uname = $_POST['uname'] ?? '';
        $psw = $_POST['psw'] ?? '';

        if ($uname === $correctUser && $psw === $correctPass) {
            $_SESSION['loggedIn'] = true;
            $_SESSION['user'] = $uname;
            return true;
        } else {
            return false;
        }
    }
    return null;
}
?>

<?php
function requireLogIn() {
    if (empty($_SESSION['loggedIn'])) {
        header("Location: login.php");
        exit;
    }
}

function logOut() {
    session_unset();
    session_destroy();
    header("Location: login.php");
    exit;
}
?>
