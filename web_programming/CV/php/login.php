<?php
include_once '../includes/config.php';
include_once '../includes/functions.php';
/** @var $baseURL */
?>
<!DOCTYPE html>
<html lang="sv">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Log in</title>
    <link rel="stylesheet" href="<?php echo $baseURL; ?>css/style.css">
</head>
<body>
<?php
include_once '../includes/header.php';
include_once '../includes/sidePanel.php';
$errorMsg = '';
if (isset($_GET['error']) && $_GET['error'] === 'notfound') {
    $errorMsg = 'Wrong username or password.';
}
?>
<div class="formBox">
    <?php if ($errorMsg): ?>
        <p style="color:red;"><?php echo $errorMsg; ?></p>
    <?php endif; ?>
    <form action="../includes/functions.php" method="post" class="formInput">
        <input type="text" name="username" placeholder="Username" class="formInput" required><br>
        <input type="password" name="password" placeholder="Password" class="formInput" required><br>
        <button type="submit" name="login" class="submitBtn">Login</button>
    </form>
</div>
<script src="<?php echo $baseURL; ?>scripts/jsFunctions.js"></script>
<?php include_once '../includes/footer.php'; ?>
</body>
</html>