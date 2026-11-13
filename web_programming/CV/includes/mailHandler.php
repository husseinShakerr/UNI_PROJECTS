<!-- https://github.com/PHPMailer/PHPMailer/blob/master/README.md-->

<!--
 Med biblioteket PHPMailer kan jag fånga nails i mitt gmail-konto enkelt.
 Exempel på användning: https://github.com/PHPMailer/PHPMailer/blob/master/examples/gmail.phps
 -->


<?php
use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\Exception;
require '../vendor/autoload.php';

if($_SERVER["REQUEST_METHOD"] == "POST"){
    $name = htmlspecialchars($_POST["name"]);
    $email = filter_var($_POST['email'], FILTER_SANITIZE_EMAIL);
    $subject = htmlspecialchars($_POST["subject"]);
    $message = htmlspecialchars($_POST["message"]);

    $mail = new PHPMailer(true);

    try {
        $mail->isSMTP();
        $mail->Host       = 'smtp.gmail.com';
        $mail->SMTPAuth   = true;
        $mail->Username   = 'z.hassoni90@gmail.com';
        $mail->Password   = getenv('SMTP_PASSWORD');
        $mail->SMTPSecure = PHPMailer::ENCRYPTION_STARTTLS;
        $mail->Port       = 587;

        $mail->setFrom("z.hassoni90@gmail.com", "Hussein");
        $mail->addReplyTo($email, $name);
        $mail->addAddress('z.hassoni90@gmail.com');

        $mail->isHTML(true);
        $mail->Subject = $subject;
        $mail->Body    = nl2br($message);

        $mail->send();

        header("Location: ../php/contact.php?success=1");
        exit;
    } catch (Exception $e) {
        header("Location: ../php/contact.php?success=0");
        exit;
    }
} else {
    header("Location: ../php/contact.php");
    exit;
}