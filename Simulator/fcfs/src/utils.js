export function calculateFCFS(processes) {
  let sorted = [...processes].sort((a, b) => a.at - b.at);
  let time = 0;
  let result = [];

  sorted.forEach((p) => {
    if (time < p.at) time = p.at; // CPU idle
    let ct = time + p.bt;
    let tat = ct - p.at;
    let wt = tat - p.bt;
    result.push({ ...p, ct, tat, wt });
    time = ct;
  });

  return result;
}
