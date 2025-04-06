//get同步
public void getSync(View view){
    new Thread(){
        @Override
        public void run() {
            Request request = new Request.Builder().url("https://www.httpbin.org/get?a=1&b=2").build();
            Call call = okHttpClient.newCall(request);
            try {
                Response response = call.execute();
                assert response.body() != null;
                Log.d(TAG,"getSync"+response.body().string());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }.start();
}

//get异步
public void getAsync(View view){
    Request request = new Request.Builder().url("https://www.httpbin.org/get?a=1&b=2").build();
    Call call = okHttpClient.newCall(request);
    call.enqueue(new Callback() {
        @Override
        public void onFailure(Call call, IOException e) {

        }

        @Override
        public void onResponse(Call call, Response response) throws IOException {
            if(response.isSuccessful()){
                Log.d(TAG,"getSync"+response.body().string());
            }
        }
    });
}

//post同步
public void postSync(View view){
    new Thread(){
        @Override
        public void run() {
            FormBody formBody = new FormBody.Builder()
                    .add("a", "1")
                    .add("b", "2")
                    .build();
            Request request = new Request.Builder()
                    .url("https://www.httpbin.org/post")
                    .post(formBody)
                    .build();
            Call call = okHttpClient.newCall(request);
            try {
                Response response = call.execute();
                Log.i(TAG,"getSync"+response.body().string());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }.start();
}

//post异步
public void postAsync(View view){
    FormBody formBody = new FormBody.Builder()
            .add("a", "1")
            .add("b", "2")
            .build();
    Request request = new Request.Builder()
            .url("https://www.httpbin.org/post")
            .post(formBody)
            .build();
    Call call = okHttpClient.newCall(request);
    call.enqueue(new Callback() {
        @Override
        public void onFailure(Call call, IOException e) {

        }

        @Override
        public void onResponse(Call call, Response response) throws IOException {
            if(response.isSuccessful()){
                Log.d(TAG,"getSync"+response.body().string());
            }
        }
    });
}