# Welcome to Sonic Pi

live_loop :foo do
  use_real_time
  a, b, c = sync "/osc*/trigger/birds"
  
  ##| Day Birds
  canary = "/Users/chiannacohen/Creative_Embedded_Systems/Project_2/Samples/canary.wav"
  whipperwhill = "/Users/chiannacohen/Creative_Embedded_Systems/Project_2/Samples/whipperwhill.wav"
  finch = "/Users/chiannacohen/Creative_Embedded_Systems/Project_2/Samples/finch.wav"
  nightingale = "/Users/chiannacohen/Creative_Embedded_Systems/Project_2/Samples/nightingale.wav"
  
  ##| Night Birds
  hawk = "/Users/chiannacohen/Creative_Embedded_Systems/Project_2/Samples/hawk.wav"
  owl = "/Users/chiannacohen/Creative_Embedded_Systems/Project_2/Samples/owl.wav"
  
  
  ##| a = 0 signals day time, a = 1 signals night time
  if a == 0
    
    sample canary, rate: 2 * b, amp: 0.1 + c
    sample canary , rate: 1 * b, amp: 0.3
    sleep rrand(0.5, 1)
    sample whipperwhill,  rate: 1, amp: 0.5 + c if one_in(15)
    sample finch, rate: 1 * b, amp: 0.5 * b + c if one_in(6)
    sample canary, rate: 1, amp: 0.5 + c if one_in(2)
    sleep rrand(0.5, 1)
    sleep b
    sample nightingale, rate: 1 * b,  amp: 1 + c if one_in(9)
    
  else
    
    sample nightingale, amp: 0.1 * c
    sleep b
    sample nightingale, amp: 0.1 * c
    sample hawk if one_in(20)
    sleep rrand(0.2, 2)
    sample owl, amp: c if one_in(10 * b)
    sleep rrand(0.2, 1)
  end
end