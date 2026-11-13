<?php
/** @var $baseURL */
?>
<!DOCTYPE html>
<html lang="sv">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Contact</title>
    <link rel="stylesheet" href="../css/style.css">
    <link rel="stylesheet" href="../css/contact.css">
</head>
<body>
<?php
include("../includes/sidePanel.php"); ?>
<main class="contactPage">
    <section class="contactInfo">
        <h2>Contact information</h2>
        <address>
            <p><strong>Name: Hussein Shaker</strong></p>
            <p><strong>E-mail: <a href="mailto:z.hassoni90@gmail.com">z.hassoni90@gmail.com</a></strong></p>
            <p><strong>Phone number: +46 73 424 65 82</strong></p>
        </address>
    </section>

    <section class="contactForm">
        <h2>Send me an E-mail</h2>

        <?php if(isset($_GET['success']) && $_GET['success'] == 1): ?>
            <p style="color:green; text-align:center;">Your message has been sent!</p>
        <?php elseif(isset($_GET['success']) && $_GET['success'] == 0): ?>
            <p style="color:red; text-align:center;">Something went wrong with sending the e-mail...please try again.</p>
        <?php endif; ?>

        <form action="<?php echo $baseURL; ?>includes/mailHandler.php" method="post">
            <input placeholder="Name" type="text" id="name" name="name" required>

            <input placeholder="Subject" type="text" id="sub" name="subject" required>

            <input placeholder="Email" type="email" id="email" name="email" required>

            <textarea placeholder="Message" id="message" name="message" rows="6" required></textarea>

            <button type="submit" class="submitBtn">Send</button>
        </form>
    </section>
</main>
<script src="<?php echo $baseURL; ?>scripts/jsFunctions.js"></script>
<?php include_once '../includes/footer.php'; ?>
</body>
</html>
