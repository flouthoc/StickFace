/*-----Stickface ( An Awesome Desktop Sticky Widget)
		Built in Gtk
		For Unity and Gnome Environment
		Tested in Ubuntu
	Author:argunner(gunnerar7@gmail.com)
	Github:https://github.com/argunner
*/



#include <gtk/gtk.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



 struct init_screen{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *frame;
  GtkWidget *hide_show_status;
  GtkWidget *combo;
  GtkWidget *hseparator;
  GtkWidget *grid;
  GtkWidget *notebook;
  GtkWidget *label;
  GtkWidget *toolbar;
  GtkWidget *textpad;
  GtkWidget *toolbar_second;
  GtkWidget *scroll;

  GtkToolItem *button_first;
  GtkToolItem *button_second;

  GtkToolItem *button_second_first;
  GtkToolItem *button_second_second;
  GtkToolItem *button_second_third;

  GtkWidget *label_for_icon_first;
  GtkTextBuffer *buffer;
  int follow_unfollow_status ;
  };


//int page_label_count_marker = 1;
int dynamic_size_shift_x_axis,dynamic_size_shift_y_axis;







gboolean on_button_press (GtkWidget* widget,
  GdkEventButton * event, GdkWindowEdge edge)
{
  if (event->type == GDK_BUTTON_PRESS)
  {
    if (event->button == 1) {
      gtk_window_begin_move_drag(GTK_WINDOW(gtk_widget_get_toplevel(widget)),
          event->button,
    event->x_root,
    event->y_root,
    event->time);
    }
  }

  return FALSE;
}





void toggle_label(GtkToolButton *widget,gpointer button_first){
  const gchar *string = gtk_tool_button_get_label(button_first);

  if(strcmp(string,"Go To Desktop")){

  gtk_tool_button_set_label(button_first,"Go To Desktop");
  gtk_tool_item_set_tooltip_text(GTK_TOOL_ITEM(button_first),"Widget Moves Itself to Desktop");
}
  else{
    gtk_tool_button_set_label(button_first,"Follow Me");
    gtk_tool_item_set_tooltip_text(GTK_TOOL_ITEM(button_first),"Widget will keep itself on top of Every Work Screen");


  }
}


void show_window_bar(GtkWindow *window){
  gtk_window_set_decorated(window,TRUE);
}

void hide_window_bar(GtkWindow *window){
  gtk_window_set_decorated(window,FALSE);
}





void hide(GtkWidget *widget,gpointer something){

  struct init_screen *any = something;
  if(any->follow_unfollow_status){
 gtk_window_set_keep_above(GTK_WINDOW(any->window),FALSE);
  gtk_window_set_keep_below(GTK_WINDOW(any->window),TRUE);
  any->follow_unfollow_status = 0;
  g_print("convertd");
   }
  else{
    gtk_window_set_keep_below(GTK_WINDOW(any->window),FALSE);
    gtk_window_set_keep_above(GTK_WINDOW(any->window),TRUE);

    any->follow_unfollow_status = 1;
    g_print("not converted");
  }

}


void about(GtkWidget *widget,gpointer data){

  GtkWidget *dialog;
  dialog = gtk_about_dialog_new();
  g_print("hello");
  gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(dialog),"StickFace");
  gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog),"1.0");
   gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), "StickFace is a Simple Tool to Enhance the Application of Native Sticky Widget.");
   gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog),"http://www.github.com/argunner");
   gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), "If You Are Contributer Add YOur Name Here.");
   gtk_dialog_run(GTK_DIALOG (dialog));
  gtk_widget_destroy(dialog);


}


void dynamic_size_shift(GtkWindow *window,GdkEvent *event){
   //printf("dsfds");
   
   char buf[10];
   dynamic_size_shift_x_axis = event->configure.width;
   dynamic_size_shift_y_axis = event->configure.height;
   sprintf(buf, "%d, %d", dynamic_size_shift_x_axis, dynamic_size_shift_y_axis);
   gtk_window_set_title(window, buf);
 }


/*void dynamic_size_shift_for_textpad(GtkWidget *widget){
  char buf[10];
   sprintf(buf, "%d, %d", dynamic_size_shift_x_axis, dynamic_size_shift_y_axis);
  g_print(buf);
  gtk_widget_set_size_request(widget,dynamic_size_shift_x_axis,dynamic_size_shift_y_axis);

}*/


/*void add_new_tab(GtkWidget *widget,gpointer notebook){
  char buffer_first[32];
  //char buffer_second[32];
  sprintf(buffer_first,"Page %d",page_label_count_marker);
  //sprintf(buffer_second,"%d",page_label_count_marker);
  frame = gtk_frame_new(buffer_first);
  //label = gtk_label_new(buffer_second);
  gtk_notebook_page_append(GTK_NOTEBOOK(notebook),frame,label);

}*/



void main_screen(){
  struct init_screen main;
  struct init_screen *p = &main;




 
 

   /* --------------------------------------------------------------------
     * I'm initialising WINDOW PART HERE TO GET WINDOW *
     -------------------------------------------------------------------- */

  main.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  //gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(main.window), 230,150);

  gtk_window_set_title(GTK_WINDOW(main.window), "StickFace");
  gtk_window_set_decorated(GTK_WINDOW (main.window), FALSE);
  gtk_widget_add_events(main.window, GDK_BUTTON_PRESS_MASK);
  gtk_window_set_keep_above(GTK_WINDOW(main.window),TRUE);
  gtk_window_set_has_resize_grip(GTK_WINDOW(main.window),TRUE);
  gtk_window_set_resizable(GTK_WINDOW(main.window),TRUE);
   main.follow_unfollow_status = 1;

 


  main.textpad = gtk_text_view_new();
  //main.buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(main.textpad));
  //gtk_text_buffer_set_text (main.buffer,string, -1);

  gtk_widget_set_size_request(main.textpad,230,150);
  gtk_widget_set_vexpand (GTK_WIDGET(main.textpad),TRUE);
  gtk_widget_set_hexpand (GTK_WIDGET(main.textpad),TRUE);
  gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(main.textpad),GTK_WRAP_WORD_CHAR);
  
  main.scroll = gtk_scrolled_window_new(NULL,NULL);
    gtk_widget_set_size_request(main.scroll,230,150);
    gtk_container_add(GTK_CONTAINER(main.scroll),main.textpad);
  








  /* --------------------------------------------------------------------
     * I'm initialising NOTEBOOK PART HERE TO GET MULTIPLE TAB FUNCTION *
     -------------------------------------------------------------------- */
/*notebook = gtk_notebook_new();
gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook),GTK_POS_TOP);

  
  frame = gtk_frame_new (NULL);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 10);
  gtk_widget_set_size_request (frame, 200, 200);
  gtk_widget_show (frame);
  
  
  gtk_container_add (GTK_CONTAINER (frame), textpad);
  //gtk_widget_show (label);
  
  label = gtk_label_new ("Page 1");
  gtk_notebook_append_page (GTK_NOTEBOOK (notebook), frame, label);*/
  









  /*  -----------------------------------------------------------
      * THIS IS A HORIZONTAL SEPERATOR  USING GRID              *
      * THIS IS HIGHLY UNSTABLE PART DAMAGES WHOLE THE SETUP    *
      * UNCOMMENT ONLY IF THIS PART HAS BEEN CHECKED SEPERATELY *
      -----------------------------------------------------------*/


  main.grid = gtk_grid_new();
   //gtk_grid_set_column_homogeneous(GTK_GRID(grid),TRUE);
   //gtk_grid_set_row_homogeneous(GTK_GRID(grid),TRUE);
   //gtk_grid_set_baseline_row(GTK_GRID(grid),0);
 
  gtk_container_add(GTK_CONTAINER(main.window),main.grid);


  

  //combo box part stll vurnuable and buggy


   /*----------------------------------------------------------------------
    *********INITIALISING COMBO AND ADDING STUFF TO COMBO******************
    -----------------------------------------------------------------------*/

  /*combo = gtk_combo_box_text_new();
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "HTML");
 gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "C/C++");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "PHP");*/



//combox box ends here

   /*----------------------------------------------------------------------
    *********CREATING ITEMS FOR TOOLBAR IN SHORT TOOL_ITEM******************
    -----------------------------------------------------------------------*/

  main.button = gtk_button_new();
  main.button_first = gtk_tool_button_new(NULL,"Go To Desktop");
  gtk_tool_item_set_tooltip_text (GTK_TOOL_ITEM(main.button_first),"Widget Moves Itself to Desktop");
  main.button_second = gtk_tool_button_new(NULL,"Exit");
  main.button_second_first = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
  gtk_tool_item_set_tooltip_text(GTK_TOOL_ITEM(main.button_second_first),"Open New Page");
  main.button_second_second = gtk_tool_button_new_from_stock(GTK_STOCK_ABOUT);
  gtk_tool_item_set_tooltip_text(GTK_TOOL_ITEM(main.button_second_second),"About Product");



  //hide_show_status = gtk_label_new("Go Away Fella");
  //gtk_container_add(GTK_CONTAINER(button),hide_show_status);


  /*---------------------------------
    *********TOOLBAR******************
    ----------------------------------*/
  main.toolbar = gtk_toolbar_new();
  gtk_toolbar_set_style(GTK_TOOLBAR(main.toolbar),GTK_TOOLBAR_TEXT);
  gtk_container_set_border_width(GTK_CONTAINER(main.toolbar), 1);


  main.toolbar_second = gtk_toolbar_new();
  gtk_toolbar_set_style(GTK_TOOLBAR(main.toolbar_second),GTK_TOOLBAR_ICONS);
  gtk_container_set_border_width(GTK_CONTAINER(main.toolbar_second),1);

 


 /*--------------------------------------------------------
    *********INSERTING INSIDE THE TOOLBAR******************
    -------------------------------------------------------*/


gtk_toolbar_insert(GTK_TOOLBAR(main.toolbar),main.button_first,-1);
gtk_toolbar_insert(GTK_TOOLBAR(main.toolbar),main.button_second,-1);

gtk_toolbar_insert(GTK_TOOLBAR(main.toolbar_second),main.button_second_first,-1);
gtk_toolbar_insert(GTK_TOOLBAR(main.toolbar_second),main.button_second_second,-1);




 /*--------------------------------------------------------
    *********ATTACHING STUFF TO GRID******************
    -------------------------------------------------------*/


    gtk_grid_attach(GTK_GRID(main.grid),main.toolbar,0,0,1,1);
  //gtk_grid_attach(GTK_GRID(grid),button,2,0,1,1);
  //gtk_grid_attach(GTK_GRID(grid),combo,3,0,9,1);
  //gtk_grid_attach(GTK_GRID(grid),hseparator,0,1,1,1);
  gtk_grid_attach(GTK_GRID(main.grid),main.scroll,0,1,1,1);
 gtk_grid_attach(GTK_GRID(main.grid),main.toolbar_second,0,2,1,1);
  //gtk_fixed_put(GTK_FIXED(frame),button,50,20);







/*-----------------------------------------------------------------------------------------
    *********MAKING ESSENTIAL SIGNAL CONNECTION AND ENDING OF APPLICATION******************
    ---------------------------------------------------------------------------------------*/

 


  g_signal_connect(G_OBJECT(main.window), "button-press-event",G_CALLBACK(on_button_press), NULL);

  g_signal_connect(main.window, "destroy",G_CALLBACK(gtk_main_quit), G_OBJECT(main.window));

  g_signal_connect(G_OBJECT(main.button_first),"clicked",G_CALLBACK(hide),p);
  g_signal_connect(G_OBJECT(main.button_first),"clicked",G_CALLBACK(toggle_label),main.button_first);
  g_signal_connect(G_OBJECT(main.button_second),"clicked",G_CALLBACK(gtk_main_quit),NULL);
  g_signal_connect(G_OBJECT(main.button_second_first),"clicked",G_CALLBACK(main_screen),NULL);
  g_signal_connect(G_OBJECT(main.button_second_second),"clicked",G_CALLBACK(about),NULL);
  g_signal_connect(G_OBJECT(main.window),"configure-event",G_CALLBACK(dynamic_size_shift),main.window);
  //g_signal_connect(G_OBJECT(window),"configure-event",G_CALLBACK(dynamic_size_shift_for_textpad),textpad);
  g_signal_connect(G_OBJECT(main.window),"enter-notify-event",G_CALLBACK(show_window_bar),main.window);
  g_signal_connect(G_OBJECT(main.window),"focus-out-event",G_CALLBACK(hide_window_bar),main.window);
  
gtk_widget_show_all(main.window);

gtk_main();
}













  void main_screen_from_data(int i,char string[][200]){

int j = 0;
int m = 0;

//char  buffer[200];

char c[20];


   

  struct init_screen main[i+1];
  while(j<i){
  struct init_screen *p = &main[j];
  
  //sprintf(buffer,"%s",&string[j][200]);

  //g_print(buffer);

sprintf(c, "%d", j);



   /* --------------------------------------------------------------------
     * I'm initialising WINDOW PART HERE TO GET WINDOW *
     -------------------------------------------------------------------- */

  main[j].window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  //gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(main[j].window), 230,150);

  gtk_window_set_title(GTK_WINDOW(main[j].window), "StickFace");
  gtk_window_set_decorated(GTK_WINDOW (main[j].window), FALSE);
  gtk_widget_add_events(main[j].window, GDK_BUTTON_PRESS_MASK);
  gtk_window_set_keep_above(GTK_WINDOW(main[j].window),TRUE);
  gtk_window_set_has_resize_grip(GTK_WINDOW(main[j].window),TRUE);
  gtk_window_set_resizable(GTK_WINDOW(main[j].window),TRUE);
   main[j].follow_unfollow_status = 1;

 
   

  main[j].textpad = gtk_text_view_new();
  main[j].buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(main[j].textpad));
  gtk_text_buffer_set_text (main[j].buffer,&string[j][200],-1);

  gtk_widget_set_size_request(main[j].textpad,230,150);
  gtk_widget_set_vexpand (GTK_WIDGET(main[j].textpad),TRUE);
  gtk_widget_set_hexpand (GTK_WIDGET(main[j].textpad),TRUE);
  gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(main[j].textpad),GTK_WRAP_WORD_CHAR);
  
  main[j].scroll = gtk_scrolled_window_new(NULL,NULL);
    gtk_widget_set_size_request(main[j].scroll,230,150);
    gtk_container_add(GTK_CONTAINER(main[j].scroll),main[j].textpad);
  








  /* --------------------------------------------------------------------
     * I'm initialising NOTEBOOK PART HERE TO GET MULTIPLE TAB FUNCTION *
     -------------------------------------------------------------------- */
/*notebook = gtk_notebook_new();
gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook),GTK_POS_TOP);

  
  frame = gtk_frame_new (NULL);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 10);
  gtk_widget_set_size_request (frame, 200, 200);
  gtk_widget_show (frame);
  
  
  gtk_container_add (GTK_CONTAINER (frame), textpad);
  //gtk_widget_show (label);
  
  label = gtk_label_new ("Page 1");
  gtk_notebook_append_page (GTK_NOTEBOOK (notebook), frame, label);*/
  









  /*  -----------------------------------------------------------
      * THIS IS A HORIZONTAL SEPERATOR  USING GRID              *
      * THIS IS HIGHLY UNSTABLE PART DAMAGES WHOLE THE SETUP    *
      * UNCOMMENT ONLY IF THIS PART HAS BEEN CHECKED SEPERATELY *
      -----------------------------------------------------------*/


  main[j].grid = gtk_grid_new();
   //gtk_grid_set_column_homogeneous(GTK_GRID(grid),TRUE);
   //gtk_grid_set_row_homogeneous(GTK_GRID(grid),TRUE);
   //gtk_grid_set_baseline_row(GTK_GRID(grid),0);
 
  gtk_container_add(GTK_CONTAINER(main[j].window),main[j].grid);


  

  //combo box part stll vurnuable and buggy


   /*----------------------------------------------------------------------
    *********INITIALISING COMBO AND ADDING STUFF TO COMBO******************
    -----------------------------------------------------------------------*/

  /*combo = gtk_combo_box_text_new();
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "HTML");
 gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "C/C++");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "PHP");*/



//combox box ends here

   /*----------------------------------------------------------------------
    *********CREATING ITEMS FOR TOOLBAR IN SHORT TOOL_ITEM******************
    -----------------------------------------------------------------------*/

  main[j].button = gtk_button_new();
  main[j].button_first = gtk_tool_button_new(NULL,"Go To Desktop");
  gtk_tool_item_set_tooltip_text (GTK_TOOL_ITEM(main[j].button_first),"Widget Moves Itself to Desktop");
  main[j].button_second = gtk_tool_button_new(NULL,"Exit");
  main[j].button_second_first = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
  gtk_tool_item_set_tooltip_text(GTK_TOOL_ITEM(main[j].button_second_first),"Open New Page");
  main[j].button_second_second = gtk_tool_button_new_from_stock(GTK_STOCK_ABOUT);
  gtk_tool_item_set_tooltip_text(GTK_TOOL_ITEM(main[j].button_second_second),"About Product");



  //hide_show_status = gtk_label_new("Go Away Fella");
  //gtk_container_add(GTK_CONTAINER(button),hide_show_status);


  /*---------------------------------
    *********TOOLBAR******************
    ----------------------------------*/
  main[j].toolbar = gtk_toolbar_new();
  gtk_toolbar_set_style(GTK_TOOLBAR(main[j].toolbar),GTK_TOOLBAR_TEXT);
  gtk_container_set_border_width(GTK_CONTAINER(main[j].toolbar), 1);


  main[j].toolbar_second = gtk_toolbar_new();
  gtk_toolbar_set_style(GTK_TOOLBAR(main[j].toolbar_second),GTK_TOOLBAR_ICONS);
  gtk_container_set_border_width(GTK_CONTAINER(main[j].toolbar_second),1);

 


 /*--------------------------------------------------------
    *********INSERTING INSIDE THE TOOLBAR******************
    -------------------------------------------------------*/


gtk_toolbar_insert(GTK_TOOLBAR(main[j].toolbar),main[j].button_first,-1);
gtk_toolbar_insert(GTK_TOOLBAR(main[j].toolbar),main[j].button_second,-1);

gtk_toolbar_insert(GTK_TOOLBAR(main[j].toolbar_second),main[j].button_second_first,-1);
gtk_toolbar_insert(GTK_TOOLBAR(main[j].toolbar_second),main[j].button_second_second,-1);




 /*--------------------------------------------------------
    *********ATTACHING STUFF TO GRID******************
    -------------------------------------------------------*/


    gtk_grid_attach(GTK_GRID(main[j].grid),main[j].toolbar,0,0,1,1);
  //gtk_grid_attach(GTK_GRID(grid),button,2,0,1,1);
  //gtk_grid_attach(GTK_GRID(grid),combo,3,0,9,1);
  //gtk_grid_attach(GTK_GRID(grid),hseparator,0,1,1,1);
  gtk_grid_attach(GTK_GRID(main[j].grid),main[j].scroll,0,1,1,1);
 gtk_grid_attach(GTK_GRID(main[j].grid),main[j].toolbar_second,0,2,1,1);
  //gtk_fixed_put(GTK_FIXED(frame),button,50,20);






/*-----------------------------------------------------------------------------------------
    *********MAKING ESSENTIAL SIGNAL CONNECTION AND ENDING OF APPLICATION******************
    ---------------------------------------------------------------------------------------*/

 


  g_signal_connect(G_OBJECT(main[j].window), "button-press-event",G_CALLBACK(on_button_press), NULL);

  g_signal_connect(main[j].window, "destroy",G_CALLBACK(gtk_main_quit), G_OBJECT(main[j].window));

  g_signal_connect(G_OBJECT(main[j].button_first),"clicked",G_CALLBACK(hide),p);
  g_signal_connect(G_OBJECT(main[j].button_first),"clicked",G_CALLBACK(toggle_label),main[j].button_first);
  g_signal_connect(G_OBJECT(main[j].button_second),"clicked",G_CALLBACK(gtk_main_quit),NULL);
  g_signal_connect(G_OBJECT(main[j].button_second_first),"clicked",G_CALLBACK(main_screen),NULL);
  g_signal_connect(G_OBJECT(main[j].button_second_second),"clicked",G_CALLBACK(about),NULL);
  g_signal_connect(G_OBJECT(main[j].window),"configure-event",G_CALLBACK(dynamic_size_shift),main[j].window);
  //g_signal_connect(G_OBJECT(window),"configure-event",G_CALLBACK(dynamic_size_shift_for_textpad),textpad);
  g_signal_connect(G_OBJECT(main[j].window),"enter-notify-event",G_CALLBACK(show_window_bar),main[j].window);
  g_signal_connect(G_OBJECT(main[j].window),"focus-out-event",G_CALLBACK(hide_window_bar),main[j].window);
  
gtk_widget_show_all(main[j].window);


j++;
}

//THE APP KIlLER LINE





  gtk_main();
  
}


 int main( int argc, char *argv[])
{


  int i = 0;  
  char buffer[200];
 char string[10][200];



  FILE *file_1;


  
gtk_init(&argc, &argv);

  
  file_1 = fopen("data_file_1.stick","r");

  /*while (fscanf(fp, "%d,%d\n", &i, &isquared) == 2)
         printf("i: %d,  isquared: %d\n", i, isquared);*/
   
  //fscanf(file_1, "%s",buffer) == 1
         
//fgets(buffer,100,file_1) != NULL

       while (fgets(buffer,100,file_1) != NULL){


       sprintf(&string[i][200], "%s",buffer);
       i = i+1;
       

       }

       

        main_screen_from_data(i,string);

  
 
       


    fclose(file_1);

 

  return 0;


  
  
  
  
}
