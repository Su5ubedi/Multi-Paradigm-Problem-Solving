(* Calculate mean using fold *)
let calculate_mean lst =
  let sum = List.fold_left (+) 0 lst in
  let length = List.length lst in
  float_of_int sum /. float_of_int length

(* Calculate median using sorting *)
let calculate_median lst =
  let sorted = List.sort compare lst in
  let length = List.length sorted in
  if length mod 2 = 0 then
    let mid1 = List.nth sorted (length / 2 - 1) in
    let mid2 = List.nth sorted (length / 2) in
    float_of_int (mid1 + mid2) /. 2.0
  else
    float_of_int (List.nth sorted (length / 2))

(* Count frequency of each element *)
let count_frequencies lst =
  let rec count_helper acc = function
    | [] -> acc
    | x :: xs ->
        let count = List.length (List.filter (fun y -> y = x) lst) in
        count_helper ((x, count) :: acc) (List.filter (fun y -> y <> x) xs)
  in
  count_helper [] lst

(* Calculate mode using functional approach *)
let calculate_mode lst =
  let frequencies = count_frequencies lst in
  let max_count = List.fold_left (fun acc (_, count) -> max acc count) 0 frequencies in
  List.map fst (List.filter (fun (_, count) -> count = max_count) frequencies)

(* Helper function to print list *)
let print_int_list lst =
  print_string "[";
  let rec print_helper = function
    | [] -> ()
    | [x] -> print_int x
    | x :: xs -> print_int x; print_string "; "; print_helper xs
  in
  print_helper lst;
  print_string "]"

(* Main function *)
let () =
  let data = [1; 2; 2; 3; 4; 4; 5] in

  print_endline "=== OCaml Statistics Calculator (Functional) ===";
  print_string "Data: ";
  print_int_list data;
  print_newline ();

  Printf.printf "Mean: %.2f\n" (calculate_mean data);
  Printf.printf "Median: %.2f\n" (calculate_median data);

  print_string "Mode(s): ";
  let modes = calculate_mode data in
  print_int_list modes;
  print_newline ()