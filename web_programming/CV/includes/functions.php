<?php
include_once __DIR__ . '/config.php';
function getDBConnection():PDO{
    $host = 'localhost';
    $db = 'cv_users';
    $user = 'root';
    $pass = '';
    $charset = 'utf8mb4';
    $dsn = "mysql:host=$host;dbname=$db;charset=$charset";
    try{
        $db = new PDO($dsn, $user, $pass, [
        PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
        PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_OBJ]);
        return $db;
    }
    catch(PDOException $e){
        throw new PDOException($e->getMessage(), (int)$e->getCode());
    }
}
function getUserByUsername($username){
    $pdo = getDBConnection();
    $stmt = $pdo->prepare("SELECT * FROM mywebsite_users WHERE username = ?");
    $stmt->execute([$username]);
    return $stmt->fetch();
}
function createUser($username, $password, $role = 'user'):void{
    $pdo = getDBConnection();
    $hashedPassword = password_hash($password, PASSWORD_DEFAULT);
    $stmt = $pdo->prepare("INSERT INTO mywebsite_users (username, password, role) VALUES (?,?,?)");
    $stmt->execute([$username, $hashedPassword, $role]);
}
function logOut():void{
    if(session_status() === PHP_SESSION_NONE){
        session_start();
    }

    session_unset();
    session_destroy();

    header('Location: login.php');
    exit();
}
function checkUser($username, $password):bool{
    try{
        $db = getDBConnection();
        $stmt = $db->prepare("SELECT * FROM mywebsite_users WHERE username = ?");
        $stmt->execute([$username]);
        $user = $stmt->fetch();
        return $user && password_verify($password, $user->password);
    }
    catch(PDOException $e){
        error_log("Database error: " . $e->getMessage());
        return false;
    }
}
if(isset($_POST['login'])){
    session_start();
    $username = $_POST['username'];
    $password = $_POST['password'];
    if(checkUser($username, $password)){
        $_SESSION['loggedIn'] = true;
        $_SESSION['username'] = $username;
        header('Location: ../php/cv.php');
    }
    else{
        header('Location: ../php/login.php?error=notfound');
    }
    exit();
}
