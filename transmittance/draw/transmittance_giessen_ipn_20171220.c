void transmittance_giessen_ipn_20171220(){

  int i = 11;
  /* for(i = 10 ; i < 50 ; i++){ */
  /*   if(i == 11 || i == 15 || i == 23 || i == 31 || i == 33 || i == 34 || i == 37 || i == 38 || i == 43 || i == 44){ */
  
      string i_str = to_string(i);
      string front = "J";
      string back_before_0 = "_before_0";
      string back_before_1 = "_before_1";
      string back_before_2 = "_before_2";
      string back_before_3 = "_before_3";
      string back_giessen = "_before";

      string filename_before_0 = front + i_str + back_before_0;
      string filename_before_1 = front + i_str + back_before_1;
      string filename_before_2 = front + i_str + back_before_2;
      string filename_before_3 = front + i_str + back_before_3;
      string filename_giessen = front + i_str + back_giessen;

      string filler = "../mark_top_left/rotation/";
      string filler_giessen = "/sps/clas/hosanko/NPS/PbWO4/Giessen/PbOW4/transmittance/";
      //      string filler_giessen = "../mark_top_left/";
      string filler2 = ".csv";

      ifstream myfile_before_0;
      ifstream myfile_before_1;
      ifstream myfile_before_2;
      ifstream myfile_before_3;
      ifstream myfile_giessen;
      string file_before_0 = filler + filename_before_0 + filler2;
      string file_before_1 = filler + filename_before_1 + filler2;
      string file_before_2 = filler + filename_before_2 + filler2;
      string file_before_3 = filler + filename_before_3 + filler2;
      string file_giessen = filler_giessen + filename_giessen + filler2;

      //      const int n = 1151;
      const int n = 576;
      const double d = 0.2;//crystal length 20cm in meter unit
      string dummy, dummy1;//read out first two rows
      double wavelength_before_0[n] = {0.}; 
      double transmittance_before_0[n] = {0.};
      double transmittance_before_1[n] = {0.};
      double transmittance_before_2[n] = {0.};
      double transmittance_before_3[n] = {0.};
      double wavelength_giessen[n] = {0.}; 
      double transmittance_giessen[n] = {0.};
      //      double delta_k[n] = {0.};
      //      double dk_max = 0.;

      int j = 0;

      myfile_before_0.open(file_before_0);
      myfile_before_1.open(file_before_1);
      myfile_before_2.open(file_before_2);
      myfile_before_3.open(file_before_3);
      myfile_giessen.open(file_giessen);
      for(j = 0 ; j < 2 ; j++) {//read and discard the first two rows
	myfile_before_0>>dummy;
	myfile_before_1>>dummy;
	myfile_before_2>>dummy;
	myfile_before_3>>dummy;
	myfile_giessen>>dummy>>dummy1;    
	//       	cout<<dummy1<<endl;;
      }
      for (j = 0 ; j < n ; j++){
	myfile_before_0>>wavelength_before_0[j]>>transmittance_before_0[j];
	myfile_before_1>>wavelength_before_0[j]>>transmittance_before_1[j];
	myfile_before_2>>wavelength_before_0[j]>>transmittance_before_2[j];
	myfile_before_3>>wavelength_before_0[j]>>transmittance_before_3[j];
	//	cout<<wavelength_before_0[j]<<endl;
      }
      for (j = 0 ; j < n ; j++){
	myfile_giessen>>wavelength_giessen[j]>>transmittance_giessen[j]>>dummy>>dummy;
	//	cout<<wavelength_giessen[j]<<endl;
      }
      //	delta_k[j] = (1/d)*log(transmittance_before_0[j]/transmittance_giessen[j]);

      /* if(j < n - 40 && j > 0){ */
      /*   if(delta_k[j]>dk_max) dk_max = delta_k[j]; */
      /* } */


      myfile_before_0.close();
      myfile_before_1.close();
      myfile_before_2.close();
      myfile_before_3.close();
      myfile_giessen.close();



      string title_front = front;
      string title_back = ", Transmittance";
      string title = title_front + i_str + title_back;
      TCanvas *c1 = new TCanvas("c1",title.c_str(),200,10,700,500);
      c1->cd();
      c1->SetGrid();

      TMultiGraph *mg = new TMultiGraph();//to draw two graphs in one canvas


      TGraph *gr_before_0 = new TGraph(n,wavelength_before_0,transmittance_before_0);
      gr_before_0->SetTitle("IPN_0");
      gr_before_0->SetLineColor(4);
      // gr_before_0->SetLineWidth(4);
      gr_before_0->SetMarkerColor(4);
      //  gr_before_0->SetMarkerStyle(21);
      gr_before_0->SetMarkerStyle(1);
      /* gr_before_0->SetTitle(title.c_str()); */
      /* gr_before_0->GetXaxis()->SetTitle("Wave Length [nm]"); */
      /* gr_before_0->GetYaxis()->SetTitle("Transmittance [%]"); */
      //  gr_before_0->Draw("ACP");
      //    gr_before_0->Draw();
      mg->Add(gr_before_0);

      TGraph *gr_before_1 = new TGraph(n,wavelength_before_0,transmittance_before_1);
      gr_before_1->SetTitle("IPN_1");
      gr_before_1->SetLineColor(4);
      gr_before_1->SetMarkerColor(4);
      gr_before_1->SetMarkerStyle(1);
      mg->Add(gr_before_1);

      TGraph *gr_before_2 = new TGraph(n,wavelength_before_0,transmittance_before_2);
      gr_before_2->SetTitle("IPN_2");
      gr_before_2->SetLineColor(4);
      gr_before_2->SetMarkerColor(4);
      gr_before_2->SetMarkerStyle(1);
      mg->Add(gr_before_2);

      TGraph *gr_before_3 = new TGraph(n,wavelength_before_0,transmittance_before_3);
      gr_before_3->SetTitle("IPN_3");
      gr_before_3->SetLineColor(4);
      gr_before_3->SetMarkerColor(4);
      gr_before_3->SetMarkerStyle(1);
      mg->Add(gr_before_3);


      
      TGraph *gr_giessen = new TGraph(n,wavelength_giessen,transmittance_giessen);
      //set the axis range after you Draw() the graph
      gr_giessen->GetXaxis()->SetRangeUser(325,900);
      gr_giessen->GetYaxis()->SetRangeUser(0,100);
      //      gr_giessen->SetName("Giessen");
      gr_giessen->SetTitle(title.c_str());
      gr_giessen->GetXaxis()->SetTitle("Wave Length [nm]");
      gr_giessen->GetYaxis()->SetTitle("Transmittance [%]");
      gr_giessen->SetLineColor(2);
      // gr_giessen->SetLineWidth(4);
      gr_giessen->SetMarkerColor(2);
      //  gr_giessen->SetMarkerStyle(21);
      gr_giessen->SetMarkerStyle(1);
      //    gr_giessen->Draw("SAME");
      gr_giessen->Draw("APL"); 
      // mg->Add(gr_giessen);
      mg->Draw("PL");
      



      /* const char *haha = title.c_str();   */
      /* mg->SetTitle("ahaha"); */
      /* mg->GetXaxis()->SetTitle("Wave Length [nm]"); */
      /* mg->GetYaxis()->SetTitle("Transmittance [%]"); */

      // TCanvas::Update() draws the frame, after which one can change it
      c1->BuildLegend();
      c1->Update();
      c1->GetFrame()->SetBorderSize(12);
      c1->Modified();



      //draw lines to mark light emission range : [400, 800]nm
      TLine *line_start = new TLine(400,0,400,100);//(x1, y1, x2, y2)
      TLine *line_finish = new TLine(800,0,800,100);
      line_start->SetLineColor(4);//bleu
      line_start->SetLineWidth(2);
      line_start->SetLineStyle(4);//dotted line
      line_finish->SetLineColor(4);//bleu
      line_finish->SetLineWidth(2);
      line_finish->SetLineStyle(2);//dotted line
      line_start->Draw("");//no need to say "SAME"
      line_finish->Draw("");

      string dir = "output/";
      string png = "_transmittance_comparison.png";
      string comb = dir + front + i_str + png;
      const char *output_before_0 = comb.c_str();
      c1->Print(output_before_0);
      c1->Close();
      /*
      //delta K
      title_back = ", Delta K";
      title = title_front + i_str + title_back;
      TCanvas *c2 = new TCanvas("c2", title.c_str(), 200, 10, 700, 500);
      c2->cd();
      c2->SetGrid();
      TGraph *gr_dk = new TGraph(n,wavelength_before_0 ,delta_k);
      gr_dk->SetMarkerColor(1);
      gr_dk->SetMarkerStyle(1);
      gr_dk->SetTitle(title.c_str());
      gr_dk->GetXaxis()->SetTitle("Wave Length [nm]");
      gr_dk->GetYaxis()->SetTitle("dK [1/m]");
      gr_dk->Draw();

      //set the axis range after you Draw() the graph
      if(i == 23){//J23 is especially have high radiation damage
      gr_dk->GetXaxis()->SetRangeUser(325,900);
      gr_dk->GetYaxis()->SetRangeUser(0.,4.);
      }
      else if(i == 11){
      gr_dk->GetXaxis()->SetRangeUser(325,900);
      gr_dk->GetYaxis()->SetRangeUser(0.,2.2);
      }
      else{
      gr_dk->GetXaxis()->SetRangeUser(325,900);
      gr_dk->GetYaxis()->SetRangeUser(0.,2.);
      }
      // TCanvas::Update() draws the frame, after which one can change it
      c2->Update();
      c2->GetFrame()->SetBorderSize(12);
      c2->Modified();


      //draw lines to mark light emission range : [400, 800]nm
      TLine *line_limit = new TLine(325,1.1,900,1.1);//radiation damage limit, dK = 1.1[1/m] in PANDA project. If dK is higher, no use to use this crystal
      if(i == 23){//J23 is especially have high radiation damage
      TLine *line_start2 = new TLine(400,0., 400, 4.);//(x1, y1, x2, y2)
      TLine *line_finish2 = new TLine(800,0.,800, 4.);
      line_start2->SetLineColor(4);//bleu
      line_start2->SetLineWidth(2);
      line_start2->SetLineStyle(2);//dotted line
      line_finish2->SetLineColor(4);//bleu
      line_finish2->SetLineWidth(2);
      line_finish2->SetLineStyle(2);//dotted line
      line_limit->SetLineColor(2);//red
      line_limit->SetLineWidth(2);
      line_limit->SetLineStyle(2);//dotted line
      line_start2->Draw("");//no need to say "SAME"
      line_finish2->Draw("");
      line_limit->Draw();
      }
      else if(i == 11){
      TLine *line_start2 = new TLine(400,0., 400, 2.2);//(x1, y1, x2, y2)
      TLine *line_finish2 = new TLine(800,0.,800, 2.2);
   
      line_start2->SetLineColor(4);//bleu
      line_start2->SetLineWidth(2);
      line_start2->SetLineStyle(2);//dotted line
      line_finish2->SetLineColor(4);//bleu
      line_finish2->SetLineWidth(2);
      line_finish2->SetLineStyle(2);//dotted line
      line_limit->SetLineColor(2);//red
      line_limit->SetLineWidth(2);
      line_limit->SetLineStyle(2);//dotted line
      line_start2->Draw("");//no need to say "SAME"
      line_finish2->Draw("");
      line_limit->Draw();
      }   
      else{
      TLine *line_start2 = new TLine(400,0., 400, 2.);//(x1, y1, x2, y2)
      TLine *line_finish2 = new TLine(800,0.,800, 2.);
   
      line_start2->SetLineColor(4);//bleu
      line_start2->SetLineWidth(2);
      line_start2->SetLineStyle(2);//dotted line
      line_finish2->SetLineColor(4);//bleu
      line_finish2->SetLineWidth(2);
      line_finish2->SetLineStyle(2);//dotted line
      line_limit->SetLineColor(2);//red
      line_limit->SetLineWidth(2);
      line_limit->SetLineStyle(2);//dotted line
      line_start2->Draw("");//no need to say "SAME"
      line_finish2->Draw("");
      line_limit->Draw();
      }   
      png = "_dK.png";
      comb = dir + front + i_str + png;
      const char *output_giessen = comb.c_str();
      c2->Print(output_giessen);

      //      c1->Close();
      c2->Close();

      ofstream outfile("dk_max.txt", ios::app);//ios::app is to append the existing file, not overwrite.
      outfile<<i_str<<"\n"
      <<"max dk   : "<<dk_max<<endl;
      outfile.close();
      */


  /*   } */
  /* } */
  return 0;
}
