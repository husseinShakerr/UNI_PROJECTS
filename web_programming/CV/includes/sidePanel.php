<?php
include_once __DIR__ . '/config.php';
if(session_status() === PHP_SESSION_NONE) session_start();
/** @var string $baseURL */
$currentPage = basename($_SERVER['PHP_SELF']);
?>
<div id="sidePanel" class="sidePanel">
    <?php if (isset($_SESSION['loggedIn']) && $_SESSION['loggedIn'] === true) : ?>
        <?php if ($currentPage !== 'cv.php'):?>
            <a href="<?php echo $baseURL; ?>php/cv.php">CV</a>
        <?php endif; ?>
        <?php if ($currentPage !== 'profile.php'): ?>
            <a href="<?php echo $baseURL; ?>php/profile.php">Profile</a>
        <?php endif; ?>
        <a href="<?php echo $baseURL; ?>php/logOut.php">Log out</a>
        <?php if ($currentPage !== 'contact.php'): ?>
            <a href="<?php echo $baseURL; ?>php/contact.php">Contact</a>
        <?php endif; ?>
    <?php else: ?>
        <?php if ($currentPage !== 'login.php'): ?>
            <a href="<?php echo $baseURL; ?>php/login.php">Log in</a>
        <?php endif; ?>
        <?php if ($currentPage !== 'register.php'): ?>
            <a href="<?php echo $baseURL; ?>php/register.php">Register</a>
        <?php endif; ?>
        <?php if ($currentPage !== 'contact.php'): ?>
            <a href="<?php echo $baseURL; ?>php/contact.php">Contact</a>
        <?php endif; ?>
    <?php endif; ?>
</div>
<button class="sidePanelBtn" onclick="toggleNav()">☰</button>
