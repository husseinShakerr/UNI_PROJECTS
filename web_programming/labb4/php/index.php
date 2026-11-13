<?php
include_once 'guestBook.php';
include_once 'guestBookPost.php';
$fileName = "guestBook.txt";
$guestBook = new GuestBook();
$guestBook->loadPosts($fileName);

if($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST["delete"])) {
    $guestBook->deletePost($_POST['delete']);
    $guestBook->savePosts($fileName);
    header("Location: " . $_SERVER["PHP_SELF"]);
    exit();
}
if($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST["name"], $_POST["comment"])){
    $post = new GuestBookPost($_POST["name"], $_POST["comment"]);
    $guestBook->addPost($post);
    $guestBook->savePosts($fileName);
    header("Location: " . $_SERVER["PHP_SELF"]);
    exit();
}
$posts = $guestBook->getPosts();

?>


<!DOCTYPE html>
<html lang="sv">
<head>
    <meta charset="utf-8">
    <title>Laboration 4</title>
    <link rel="stylesheet" href="../css/visitors.css">
</head>
<body>
<h1>Visitors</h1>
<form method="post">
    Namn: <input type="text" name="name" required><br>
    Kommentar: <textarea name="comment" required></textarea><br>
    <button type="submit">Lägg upp</button>
</form>
<hr>
<?php if(!empty($posts)): ?>
    <?php foreach (array_reverse($posts) as $post): ?>
        <div>
            <strong><?php echo htmlspecialchars($post->getName()); ?></strong>-
            <?php echo htmlspecialchars($post->getComment()); ?> -
            <?php echo htmlspecialchars($post->getFormattedDate()); ?>
            <form method="post" style="display:inline;">
                <input type="hidden" name="delete" value="<?php echo $post->getId(); ?>">
                <button type="submit">Ta bort</button>
            </form>
        </div>
    <?php endforeach; ?>
<?php endif; ?>
</body>
</html>