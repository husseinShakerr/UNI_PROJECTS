<?php
include_once '../includes/functions.php';
/** @var string $baseURL*/
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $userName = trim($_POST['username']);
    $passWord = $_POST['password'] ?? '';
    $confirmPassword = $_POST['confirmPassword'] ?? '';

    if ($userName === "" || $passWord === "" || $confirmPassword == "") {
        $error = "All fields are required";
    } elseif ($passWord != $confirmPassword) {
        $error = "Passwords do not match";
    } elseif (getUserByUsername($userName)) {
        $error = "Username already exists";
    } else {
        createUser($userName, $passWord);
        $_SESSION['loggedIn'] = true;
        $_SESSION['username'] = $userName;
        header('Location: cv.php');
        exit();
    }
}
?>
<!doctype html>
<html lang="sv">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Register</title>
    <link rel="stylesheet" href="<?php echo $baseURL; ?>css/style.css">
</head>
<body>
<?php
include_once '../includes/header.php';
include_once '../includes/sidePanel.php';
?>
<div class="formBox">
    <form action="register.php" method="post" class="formInput">
        <input type="text" name="username" placeholder="Username" class="formInput" required><br>
        <input type="password" name="password" placeholder="Password" class="formInput" required><br>
        <input type="password" name="confirmPassword" placeholder="Confirm password" class="formInput" required><br>
        <button type="submit" name="register" class="submitBtn">Register</button>
    </form>
    <?php if(isset($error)):?>
        <p style="color:red; text-align:center;"><?php echo $error ?></p>
    <?php endif;?>
</div>
<script src="<?php echo $baseURL; ?>scripts/jsFunctions.js"></script>
<?php include_once '../includes/footer.php'; ?>
</body>
</html>
