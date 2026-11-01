// Concept interface only; runtime validation and a compiler are not implemented here.
type LockedRef = { id: string; version: string; digest: string };

interface GraphIR {
  id: string;
  revision: string;
  entry: string;
  terminals: string[];

  nodes: Array<{
    id: string;
    kind: "invoke" | "branch" | "fork" | "join" | "map" | "loop" | "wait" | "terminal";
    contract: LockedRef;
    config: Record<string, unknown>; // 还需按 kind 校验
  }>;

  controlEdges: Array<{ from: string; outcome: string; to: string }>;
  dataBindings: Array<{
    to: { node: string; port: string };
    from:
      | { kind: "runInput"; pointer: string }
      | { kind: "nodeOutput"; node: string; port: string; frame: "current" };
  }>;

  joins: Array<{
    node: string;
    fork: string;
    mode: "all_activated_success";
    onChildFailure: "fail_group";
    onEmpty: "continue" | "error";
  }>;
  limits: { maxActivations: number; maxWallTimeMs: number };
  registryLock: LockedRef[];
}
