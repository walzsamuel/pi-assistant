<?php

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| API Routes
|--------------------------------------------------------------------------
|
| Here is where you can register API routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| is assigned the "api" middleware group. Enjoy building your API!
|
*/

Route::middleware('auth:api')->get('/user', function (Request $request) {
    return $request->user();
})->middleware('cors');

Route::group(['middleware' => 'cors'], function() {
    Route::get('test', function () {
        return response([1,2,3,4], 200);
    });

//    Route::group([
//        'prefix' => 'auth'
//    ], function () {
//        Route::post('login', 'AuthController@login');
//        Route::post('signup', 'AuthController@signup');
//
//        Route::group([
//            'middleware' => 'auth:api'
//        ], function() {
//            Route::get('logout', 'AuthController@logout');
//            Route::get('user', 'AuthController@user');
//        });
//    });
});