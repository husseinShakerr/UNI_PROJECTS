<?php
class GuestBook{
    private $posts = array();

    public function __construct(){
    }
    public function addPost($post){
        $this->posts[] = $post;
    }
    public function deletePost($id){
        foreach($this->posts as $key => $post){
            if($post->getId() === $id){
                unset($this->posts[$key]);
                break;
            }
        }
        $this->posts = array_values($this->posts);
    }

    public function loadPosts($filename){
        if(file_exists($filename)){
            $data = file_get_contents($filename);
            $this->posts = unserialize($data);
        }
    }

    public function savePosts($filename){
        file_put_contents($filename, serialize($this->posts));
    }

    public function getPosts(){
        return $this->posts;
    }
}
