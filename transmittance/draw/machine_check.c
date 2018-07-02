void machine_check(string filename){

  ifstream myfile;
  string dummy;


  const int n = 601; 
  double wavelength[n] = {0.};
  double T_slow_20171215[n] = {0.};
  double T_fast_20171215[n] = {0.};
  double E_fast_20171215[n] = {0.};
  double E_slow_20171215[n] = {0.};
  double T_fast_20171218[n] = {0.};
  double T_slow_20171218[n] = {0.};
  double E_fast_20171218[n] = {0.};

  double T_12_20171219[n] = {0.};
  double T_16_20171219[n] = {0.};
  double T_24_20171219[n] = {0.};
  double E_12_20171219[n] = {0.};

  ifstream myfile2;
  myfile2.open("../T_PWO_20-036_0.12s_20171219.Sample.Raw.csv");
  ifstream myfile3;
  myfile3.open("../T_PWO_20-036_0.16s_20171219.Sample.Raw.csv");
  ifstream myfile4;
  myfile4.open("../T_PWO_20-036_0.24s_20171219.Sample.Raw.csv");
  ifstream myfile5;
  myfile5.open("../E1_PWO_20-036_0.12s_20171219.Sample.Processed.csv");

  int i;

  myfile.open(filename);
  for(i = 0 ; i < 14 ; i++){//removinging dummies
    myfile>>dummy;
    //  cout<<dummy<<endl;
  }
  for (i = 0 ; i < n ; i++){
    myfile>>wavelength[i]>>T_slow_20171215[i]>>T_fast_20171215[i]>>dummy>>dummy>>E_fast_20171215[i]>>dummy>>dummy>>E_slow_20171215[i]>>T_fast_20171218[i]>>T_slow_20171218[i]>>dummy>>dummy>>E_fast_20171218[i];
    //   cout<<E_fast_20171218[i]<<endl;
  }


  for(i = 0 ; i < 2 ; i++){//removinging dummies
    myfile2>>dummy;
    myfile3>>dummy;
    myfile4>>dummy;
    myfile5>>dummy;
  }

  for (i = 0 ; i < n ; i++){
    myfile2>>dummy/*wavelength[i]*/>>T_12_20171219[i];
    myfile3>>dummy/*wavelength[i]*/>>T_16_20171219[i];
    myfile4>>dummy/*wavelength[i]*/>>T_24_20171219[i];
    myfile5>>dummy/*wavelength[i]*/>>E_12_20171219[i];
  }



    TCanvas *c1 = new TCanvas("c1","c1",200,10,1400,1000);
    c1->cd();
    c1->SetGrid();

    TMultiGraph *mg = new TMultiGraph();

    TGraph *gr_T_slow_20171215 = new TGraph(n,wavelength,T_slow_20171215);
    gr_T_slow_20171215->SetLineColor(1);
    // gr_before->SetLineWidth(4);
    gr_T_slow_20171215->SetMarkerColor(1);
    //  gr_before->SetMarkerStyle(21);
    gr_T_slow_20171215->SetMarkerStyle(1);
    gr_T_slow_20171215->SetTitle("transmittance PWO 20-036");
    gr_T_slow_20171215->GetXaxis()->SetTitle("Wave Length [nm]");
    gr_T_slow_20171215->GetYaxis()->SetTitle("Transmittance [%]");
    mg->Add(gr_T_slow_20171215);


    TGraph *gr_T_fast_20171215 = new TGraph(n,wavelength,T_fast_20171215);
    gr_T_fast_20171215->SetLineColor(2);
    // gr_T_fast_20171215->SetLineWidth(4);
    gr_T_fast_20171215->SetMarkerColor(2);
    //  gr_T_fast_20171215->SetMarkerStyle(21);
    gr_T_fast_20171215->SetMarkerStyle(1);
    //    gr_T_fast_20171215->Draw("SAME");
    mg->Add(gr_T_fast_20171215);

    TGraph *gr_E_fast_20171215 = new TGraph(n,wavelength,E_fast_20171215);
    gr_E_fast_20171215->SetLineColor(3);
    // gr_E_fast_20171215->SetLineWidth(4);
    gr_E_fast_20171215->SetMarkerColor(3);
    //  gr_E_fast_20171215->SetMarkerStyle(21);
    gr_E_fast_20171215->SetMarkerStyle(1);
    //    gr_E_fast_20171215->Draw("SAME");
    mg->Add(gr_E_fast_20171215);

    TGraph *gr_E_slow_20171215 = new TGraph(n,wavelength,E_slow_20171215);
    gr_E_slow_20171215->SetLineColor(4);
    // gr_E_slow_20171215->SetLineWidth(4);
    gr_E_slow_20171215->SetMarkerColor(4);
    //  gr_E_slow_20171215->SetMarkerStyle(21);
    gr_E_slow_20171215->SetMarkerStyle(1);
    //    gr_E_slow_20171215->Draw("SAME");
    mg->Add(gr_E_slow_20171215);


    TGraph *gr_T_slow_20171218 = new TGraph(n,wavelength,T_slow_20171218);
    gr_T_slow_20171218->SetLineColor(5);
    // gr_before->SetLineWidth(4);
    gr_T_slow_20171218->SetMarkerColor(5);
    //  gr_before->SetMarkerStyle(21);
    gr_T_slow_20171218->SetMarkerStyle(1);
    mg->Add(gr_T_slow_20171218);


    TGraph *gr_T_fast_20171218 = new TGraph(n,wavelength,T_fast_20171218);
    gr_T_fast_20171218->SetLineColor(6);
    // gr_T_fast_20171218->SetLineWidth(4);
    gr_T_fast_20171218->SetMarkerColor(6);
    //  gr_T_fast_20171218->SetMarkerStyle(21);
    gr_T_fast_20171218->SetMarkerStyle(1);
    //    gr_T_fast_20171218->Draw("SAME");
    mg->Add(gr_T_fast_20171218);

    TGraph *gr_E_fast_20171218 = new TGraph(n,wavelength,E_fast_20171218);
    gr_E_fast_20171218->SetLineColor(7);
    // gr_E_fast_20171218->SetLineWidth(4);
    gr_E_fast_20171218->SetMarkerColor(7);
    //  gr_E_fast_20171218->SetMarkerStyle(21);
    gr_E_fast_20171218->SetMarkerStyle(1);
    //    gr_E_fast_20171218->Draw("SAME");
    mg->Add(gr_E_fast_20171218);

    TGraph *gr_T_12_20171219 = new TGraph(n,wavelength,T_12_20171219);
    gr_T_12_20171219->SetLineColor(8);
    // gr_T_12_20171219->SetLineWidth(4);
    gr_T_12_20171219->SetMarkerColor(7);
    //  gr_T_12_20171219->SetMarkerStyle(21);
    gr_T_12_20171219->SetMarkerStyle(1);
    //    gr_T_12_20171219->Draw("SAME");
    mg->Add(gr_T_12_20171219);

    TGraph *gr_T_16_20171219 = new TGraph(n,wavelength,T_16_20171219);
    gr_T_16_20171219->SetLineColor(8);
    // gr_T_16_20171219->SetLineWidth(4);
    gr_T_16_20171219->SetMarkerColor(7);
    //  gr_T_16_20171219->SetMarkerStyle(21);
    gr_T_16_20171219->SetMarkerStyle(1);
    //    gr_T_16_20171219->Draw("SAME");
    mg->Add(gr_T_16_20171219);

    TGraph *gr_T_24_20171219 = new TGraph(n,wavelength,T_24_20171219);
    gr_T_24_20171219->SetLineColor(8);
    // gr_T_24_20171219->SetLineWidth(4);
    gr_T_24_20171219->SetMarkerColor(7);
    //  gr_T_24_20171219->SetMarkerStyle(21);
    gr_T_24_20171219->SetMarkerStyle(1);
    //    gr_T_24_20171219->Draw("SAME");
    mg->Add(gr_T_24_20171219);

    TGraph *gr_E_12_20171219 = new TGraph(n,wavelength,E_12_20171219);
    gr_E_12_20171219->SetLineColor(8);
    // gr_E_12_20171219->SetLineWidth(4);
    gr_E_12_20171219->SetMarkerColor(7);
    //  gr_E_12_20171219->SetMarkerStyle(21);
    gr_E_12_20171219->SetMarkerStyle(1);
    //    gr_E_12_20171219->Draw("SAME");
    mg->Add(gr_E_12_20171219);

    mg->Draw("APL");

    //set the axis range after you Draw() the graph
    mg->GetXaxis()->SetRangeUser(325,900);
    mg->GetYaxis()->SetRangeUser(0,100);


    // TCanvas::Update() draws the frame, after which one can change it
    c1->Update();
    c1->GetFrame()->SetBorderSize(12);
    c1->Modified();
    c1->Print("output/transmittance_slow_fast2.png");

  return 0;
}
