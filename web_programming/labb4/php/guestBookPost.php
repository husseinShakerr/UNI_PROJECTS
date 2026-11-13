<?php
class GuestBookPost{
    private $name;
    private $comment;
    private $timestamp;
    private $id;

    public function __construct($name, $comment, $timestamp = null, $id = null){
        $this->name = $name;
        $this->comment = $comment;
        $this->timestamp = is_numeric($timestamp) ? (int)$timestamp : strtotime($timestamp ?? "now"); //Inbyggd php funktion som returnerar nuvarandetid om inte tid = null.
        $this->id =  $id ?? uniqid();  //Generear unikt id om id == null så man enkelt kan radera inlägg i gästboken.
    }
    public function getName(){
        return $this->name;
    }
    public function getComment(){
        return $this->comment;
    }
    public function getFormattedDate(){
        return date("Y-m-d H:i:s", $this->timestamp);
    }
    public function getId(){
        return $this->id;
    }
}