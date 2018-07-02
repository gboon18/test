void transmittance_giessen_ipn(){

  int i = 11;
  for(i = 10 ; i < 50 ; i++){
    if(i == 11 || i == 15 || i == 23 || i == 31 || i == 33 || i == 34 || i == 37 || i == 38 || i == 43 || i == 44){
  
      string i_str = to_string(i);
      string front = "J";
      string back_before = "_before";
      string back_irr = "_before";

      string filename_before = front + i_str + back_before;
      string filename_irr = front + i_str + back_irr;

      string filler = "../mark_top_right/";
      string filler_giessen = "/sps/clas/hosanko/NPS/PbWO4/Giessen/PbOW4/transmittance/";
      //      string filler_giessen = "../mark_top_left/";
      string filler2 = ".csv";

      ifstream myfile_before;
      ifstream myfile_irr;
      string file_before = filler + filename_before + filler2;
      string file_irr = filler_giessen + filename_irr + filler2;

      //      const int n = 1151;
      const int n = 576;
      const double d = 0.2;//crystal length 20cm in meter unit
      string dummy, dummy1;//read out first two rows
      double wavelength_before[n] = {0.}; 
      double transmittance_before[n] = {0.};
      double wavelength_irr[n] = {0.}; 
      double transmittance_irr[n] = {0.};
      //      double delta_k[n] = {0.};
      //      double dk_max = 0.;

      int j = 0;

      myfile_before.open(file_before);
      myfile_irr.open(file_irr);
      for(j = 0 ; j < 2 ; j++) {//read and discard the first two rows
	myfile_before>>dummy;
	myfile_irr>>dummy>>dummy1;    
	//       	cout<<dummy1<<endl;;
      }
      for (j = 0 ; j < n ; j++){
	myfile_before>>wavelength_before[j]>>transmittance_before[j];
	//	cout<<wavelength_before[j]<<endl;
      }
      for (j = 0 ; j < n ; j++){
	myfile_irr>>wavelength_irr[j]>>transmittance_irr[j]>>dummy>>dummy;
	//	cout<<wavelength_irr[j]<<endl;
      }
      //	delta_k[j] = (1/d)*log(transmittance_before[j]/transmittance_irr[j]);

      /* if(j < n - 40 && j > 0){ */
      /*   if(delta_k[j]>dk_max) dk_max = delta_k[j]; */
      /* } */


      myfile_before.close();
      myfile_irr.close();



      string title_front = front;
      string title_back = ", Transmittance";
      string title = title_front + i_str + title_back;
      TCanvas *c1 = new TCanvas("c1",title.c_str(),200,10,700,500);
      c1->cd();
      c1->SetGrid();

      TMultiGraph *mg = new TMultiGraph();//to draw two graphs in one canvas


      TGraph *gr_before = new TGraph(n,wavelength_before,transmittance_before);
      gr_before->SetTitle("IPN");
      gr_before->SetLineColor(4);
      // gr_before->SetLineWidth(4);
      gr_before->SetMarkerColor(4);
      //  gr_before->SetMarkerStyle(21);
      gr_before->SetMarkerStyle(1);
      /* gr_before->SetTitle(title.c_str()); */
      /* gr_before->GetXaxis()->SetTitle("Wave Length [nm]"); */
      /* gr_before->GetYaxis()->SetTitle("Transmittance [%]"); */
      //  gr_before->Draw("ACP");
      //    gr_before->Draw();
      mg->Add(gr_before);


      
      TGraph *gr_irr = new TGraph(n,wavelength_irr,transmittance_irr);
      //set the axis range after you Draw() the graph
      gr_irr->GetXaxis()->SetRangeUser(325,900);
      gr_irr->GetYaxis()->SetRangeUser(0,100);
      //      gr_irr->SetName("Giessen");
      gr_irr->SetTitle(title.c_str());
      gr_irr->GetXaxis()->SetTitle("Wave Length [nm]");
      gr_irr->GetYaxis()->SetTitle("Transmittance [%]");
      gr_irr->SetLineColor(2);
      // gr_irr->SetLineWidth(4);
      gr_irr->SetMarkerColor(2);
      //  gr_irr->SetMarkerStyle(21);
      gr_irr->SetMarkerStyle(1);
      //    gr_irr->Draw("SAME");
      gr_irr->Draw("APL"); 
      // mg->Add(gr_irr);
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
      const char *output_before = comb.c_str();
      c1->Print(output_before);
      c1->Close();
      /*
      //delta K
      title_back = ", Delta K";
      title = title_front + i_str + title_back;
      TCanvas *c2 = new TCanvas("c2", title.c_str(), 200, 10, 700, 500);
      c2->cd();
      c2->SetGrid();
      TGraph *gr_dk = new TGraph(n,wavelength_before ,delta_k);
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
      const char *output_irr = comb.c_str();
      c2->Print(output_irr);

      //      c1->Close();
      c2->Close();

      ofstream outfile("dk_max.txt", ios::app);//ios::app is to append the existing file, not overwrite.
      outfile<<i_str<<"\n"
      <<"max dk   : "<<dk_max<<endl;
      outfile.close();
      */


    }
  }
  return 0;
}
