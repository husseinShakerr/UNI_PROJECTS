<?php
include_once "../includes/functions.php";
include_once '../includes/auth.php';
/** @var $baseURL */
?>
<!doctype html>
<html lang="sv">
<head>
    <title>Profile</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/style.css">
    <link rel="stylesheet" href="../css/profileStyle.css">
</head>
<body>
<?php include_once '../includes/sidePanel.php'; ?>
<main>
    <section aria-labelledby="about-heading" class="pContainer">
        <h2 id="about-heading">About me</h2>
        <article>
            <p>
                My name is Hussein Shaker. I am a technically minded problem-solver with hands-on experience
                in both IT support and mobile device repair. Through roles at Phonefix, H1 Communications, and Coop,
                I have developed strong skills in troubleshooting, customer service, and guiding users through
                technical solutions, from simple queries to complex issues.
            </p>

            <p>
                I thrive in environments where I can combine technical expertise with clear communication,
                and I enjoy helping others overcome challenges while learning new skills myself.
            </p>

            <p>
                Currently studying Computer Science, I enjoy identifying more efficient solutions, performing
                measurements, and applying both the knowledge I gained during my Electrical and Energy Program
                education and my current studies. Combining practical skills with analytical thinking allows me
                to continuously improve processes and results.
            </p>

            <p>
                I’m fluent in Arabic and Swedish, and I speak English very well too. When I’m not working or
                studying, you’ll find me lifting weights at the gym, trying to convince my guitar to sound better
                than it did yesterday, or joking around with friends. I’m a social person who enjoys keeping the
                vibe light and fun.
            </p>
        </article>
    </section>
</main>
<?php  include_once "../includes/footer.php"; ?>
<script src="<?php echo $baseURL; ?>scripts/jsFunctions.js"></script>
</body>
</html>
