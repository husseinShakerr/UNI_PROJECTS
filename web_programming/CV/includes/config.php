<?php
/** @var  $baseURL */
$host = $_SERVER['HTTP_HOST'];
if(strpos($host, 'cv.local') !== false){
    $baseURL = '/';
}
else{
    $baseURL = 'https://studenter.miun.se/~hual2302/webb/CV/';
}