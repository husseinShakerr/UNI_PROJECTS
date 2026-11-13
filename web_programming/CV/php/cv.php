<?php
include_once '../includes/functions.php';
include_once '../includes/auth.php';
/** @var $baseURL */
?>
<!DOCTYPE html>
<html lang="sv">
<head>
    <title>CV</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/style.css">
    <link rel="stylesheet" href="../css/cvStyle.css">
</head>
<body>
<?php include_once '../includes/sidePanel.php'; ?>
<main>
    <section aria-labelledby="education-heading" class="cv-container">
        <h2 id="education-heading">Educations</h2>

        <article class="exp_edu_box">
            <h3>Electrical and energy program</h3>
            <div class="job-details">
                <h4>2020</h4>
                <a href="../includes/yrkesexamen.pdf">Degree certificate (PDF)</a>
            </div>
        </article>

        <article class="exp_edu_box">
            <h3>Computer Science</h3>
            <div class="job-details">
                <h4>2026</h4>
                <p>*Ongoing</p>
            </div>
        </article>
    </section>

    <section aria-labelledby="experience-heading" class="cv-container">
        <h2 id="experience-heading">Professional Experience</h2>

        <article class="exp_edu_box">
            <h3>Phonefix</h3>
            <div class="job-details">
                <h4>September 2018 – July 2019</h4>
                <ul>
                    <li>Developed core technical skills in mobile and tablet repair.</li>
                    <li>Performed hardware replacements and diagnostics on various devices.</li>
                    <li>Resolved software issues, including OS updates, driver installation, and system recovery.</li>
                </ul>
            </div>
        </article>

        <article class="exp_edu_box">
            <h3>H1 Communications</h3>
            <div class="job-details">
                <h4>December 2019 – December 2021</h4>
                <ul>
                    <li>Provided remote technical support and troubleshooting via phone.</li>
                    <li>Guided customers through step-by-step solutions, from simple queries to complex technical issues.</li>
                    <li>Strengthened communication and customer service skills in a fast-paced call center environment.</li>
                </ul>
            </div>
        </article>

        <article class="exp_edu_box">
            <h3>Coop</h3>
            <div class="job-details">
                <h4>December 2021 – August 2025</h4>
                <ul>
                    <li>Provided remote technical support and troubleshooting via phone.</li>
                    <li>Guided customers through step-by-step solutions, from simple queries to complex technical issues.</li>
                    <li>Strengthened communication and customer service skills in a fast-paced call center environment.</li>
                </ul>
            </div>
        </article>
    </section>
</main>
<script src="<?php echo $baseURL; ?>scripts/jsFunctions.js"></script>
<?php include_once '../includes/footer.php'; ?>
</body>
</html>
