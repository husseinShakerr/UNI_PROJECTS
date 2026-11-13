<?php
class guestBookDB{
    private $pdo;

    public function __construct($host, $dbname, $userName, $password){
        $dsn = "mysql:host=$host;dbname=$dbname;charset=utf8mb4";
        $this->pdo = new PDO($dsn, $userName, $password);
        $this->pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    }
    public function getConnection(){
        return $this->pdo;
    }
    public function addPost(GuestBookPost $post) {
        $stmt = $this->pdo->prepare("INSERT INTO guestbook_posts (name, comment, timeStamp) VALUES (?, ?, NOW())");
        $stmt->execute([$post->getName(), $post->getComment()]);
    }

    public function getPosts(){
        $stmt = $this->pdo->prepare("SELECT * FROM guestbook_posts ORDER BY timeStamp DESC");
        $stmt->execute();
        $rows = $stmt->fetchAll(PDO::FETCH_ASSOC);

        $posts = [];
        foreach($rows as $row){
            $posts[] = new guestBookPost($row['name'], $row['comment'], $row['timeStamp'], $row['id']);
        }
        return $posts;
    }

    public function deletePost($id){
        $stmt = $this->pdo->prepare("DELETE FROM guestbook_posts WHERE id = ?");
        $stmt->execute([$id]);
    }
}