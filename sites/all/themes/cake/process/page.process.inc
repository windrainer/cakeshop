<?php

/**
 * Implements hook_process_page().
 */
function cake_process_page(&$var) {

 $is_front = $var['is_front'];
  if($is_front) {
    $node = menu_get_object();
    if(!$node)
      $var['title'] = '';

    //add a serial 'icon_n' to menu item style.
    $main_menu_items = $var['page']['navigation']['system_main-menu'];
    $i=0;
    foreach($main_menu_items as $key=>$value) {
      if(is_numeric($key)) {
        $class_array=$main_menu_items[$key]['#attributes']['class'];
        array_push($class_array, 'icon_'.$i);
        $main_menu_items[$key]['#attributes']['class'] = $class_array;
        //kpr($class_array);
        $i++;
      }
    }
    $var['page']['navigation']['system_main-menu'] = $main_menu_items;

  }

}
